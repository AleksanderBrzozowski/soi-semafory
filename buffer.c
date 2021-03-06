//
// Created by abrzozowski on 05.12.17.
//

#include <wchar.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include "buffer.h"
#include "semaphore.h"
#include "shared_memory.h"


void print_buff(const Buffer *buff);

void print_actual_time();

void set_can_pop(const Buffer *buff);

void check_can_put(char value);

void set_next_put_value(Buffer *buff, char put_value);

void buffer_init() {
    int shm_id = get_shared_memory(sizeof(Buffer));
    set_semaphore_val(SEM_BUFF_MUTEX, 1);
    set_semaphore_val(SEM_BUFF_EMPTY, 0);
    set_semaphore_val(SEM_BUFF_FULL, BUFF_SIZE);
    set_semaphore_val(SEM_BUFF_CAN_POP, 0);
    set_semaphore_val(SEM_BUFF_PUT_A, 1);
    set_semaphore_val(SEM_BUFF_PUT_B, 0);
    Buffer *buff = (Buffer *) shmat(shm_id, NULL, 0);
    buff->size = 0;
    buff->prev_a_count = 1;
    buff->prev_b_count = 0;
}

void buffer_put(Buffer *buff, char value) {
    check_can_put(value);
    semaphore_dec(SEM_BUFF_FULL);

    semaphore_dec(SEM_BUFF_MUTEX);
    buff->data[buff->size] = value;
    ++buff->size;
    print_buff(buff);
    set_can_pop(buff);
    set_next_put_value(buff, value);
    semaphore_inc(SEM_BUFF_MUTEX);

    semaphore_inc(SEM_BUFF_EMPTY);
}

char buffer_pop(Buffer *buff) {
    semaphore_dec(SEM_BUFF_EMPTY);

    semaphore_dec(SEM_BUFF_CAN_POP);
    semaphore_dec(SEM_BUFF_MUTEX);
    --buff->size;
    const char pop_val = buff->data[buff->size];
    set_can_pop(buff);
    print_buff(buff);
    semaphore_inc(SEM_BUFF_MUTEX);

    semaphore_inc(SEM_BUFF_FULL);
    return pop_val;
}

Buffer *get_buff() {
    int shm_id = get_shared_memory(sizeof(Buffer));
    return (Buffer *) shmat(shm_id, NULL, 0);
}

void check_can_put(char value) {
    if (value == 'A') {
        semaphore_dec(SEM_BUFF_PUT_A);
    } else if (value == 'B') {
        semaphore_dec(SEM_BUFF_PUT_B);
    } else {
        fprintf(stdout, "Value: %c is unknown. Unable to put to buffer", value);
        exit(1);
    }
}

void set_can_pop(const Buffer *buff) {
    if (buff->size > BUFF_MIN) {
        set_semaphore_val(SEM_BUFF_CAN_POP, 1);
    }
}

void set_next_put_value(Buffer *buff, char put_value) {
    if (put_value == 'A') {
        ++buff->prev_a_count;
        if (buff->prev_a_count == MAX_PREV_A) {
            buff->prev_a_count = 0;
            semaphore_inc(SEM_BUFF_PUT_B);
        } else {
            semaphore_inc(SEM_BUFF_PUT_A);
        }
    } else if (put_value == 'B') {
        ++buff->prev_b_count;
        if (buff->prev_b_count == MAX_PREV_B) {
            buff->prev_b_count = 0;
            semaphore_inc(SEM_BUFF_PUT_A);
        } else {
            semaphore_inc(SEM_BUFF_PUT_B);
        }
    }
}

void print_buff(const Buffer *buff) {
    print_actual_time();
    fprintf(stdout, "Actual Buffer: [");
    for (int j = 0; j < buff->size; ++j) {
        const char value = buff->data[j];
        if (j < buff->size - 1) {
            fprintf(stdout, "%c, ", value);
        } else {
            fprintf(stdout, "%c", value);
        }
    }
    fprintf(stdout, "], size: %d\n", buff->size);
}

void print_actual_time() {
    struct timeval tm_now;
    struct tm *tm;
    char buf[26], usec_buf[6];
    gettimeofday(&tm_now, NULL);
    tm = localtime(&tm_now.tv_sec);
    strftime(buf, 26, "%H:%M:%S", tm);
    strcat(buf, ".");
    sprintf(usec_buf, "%d", (int) tm_now.tv_usec);
    strcat(buf, usec_buf);

    fprintf(stdout, "%s: ", buf);
}

