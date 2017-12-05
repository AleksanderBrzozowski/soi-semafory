//
// Created by abrzozowski on 05.12.17.
//

#include <wchar.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "buffer.h"
#include "semaphore.h"
#include "shared_memory.h"


void print_buff(Buffer *buff);

void print_actual_time();

void set_can_pop(const Buffer *buff);

void buffer_init() {
    int shm_id = get_shared_memory(sizeof(Buffer));
    set_semaphore_val(SEM_BUFF_MUTEX, 0);
    set_semaphore_val(SEM_BUFF_EMPTY, 0);
    set_semaphore_val(SEM_BUFF_FULL, BUFF_SIZE);
    set_semaphore_val(SEM_BUFF_CAN_POP, 0);
    Buffer *buff = (Buffer *) shmat(shm_id, NULL, 0);
    buff->size = 0;
}

void buffer_put(Buffer *buff, char value) {
    semaphore_dec(SEM_BUFF_FULL);

    semaphore_inc(SEM_BUFF_MUTEX);
    buff->data[buff->size] = value;
    ++buff->size;
    print_buff(buff);
    set_can_pop(buff);
    semaphore_dec(SEM_BUFF_MUTEX);

    semaphore_inc(SEM_BUFF_EMPTY);
}

char buffer_pop(Buffer *buff) {
    semaphore_dec(SEM_BUFF_EMPTY);

    semaphore_dec(SEM_BUFF_CAN_POP);
    semaphore_inc(SEM_BUFF_MUTEX);
    --buff->size;
    const char pop_val = buff->data[buff->size];
    set_can_pop(buff);
    print_buff(buff);
    semaphore_dec(SEM_BUFF_MUTEX);

    semaphore_inc(SEM_BUFF_FULL);
    return pop_val;
}

Buffer *get_buff() {
    int shm_id = get_shared_memory(sizeof(Buffer));
    return (Buffer *) shmat(shm_id, NULL, 0);
}

void set_can_pop(const Buffer *buff) {
    if (buff->size > BUFF_MIN) {
        set_semaphore_val(SEM_BUFF_CAN_POP, 1);
    }
}

void print_buff(Buffer *buff) {
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

