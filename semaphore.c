//
// Created by abrzozowski on 04.12.17.
//

#include <errno.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include "semaphore.h"

static struct sembuf buf;

int get_semaphore_set() ;

int set_semaphore_val(unsigned int sem_num, unsigned int initial_value) {
    int sem_id = get_semaphore_set();
    if (semctl(sem_id, sem_num, SETVAL, initial_value) == -1)
    {
        fprintf(stderr, "Cannot init semaphore with sem_num: %d", sem_num);
        exit(1);
    }
}

int get_semaphore_set() {
    int existing_sem_id = semget(SEM_KEY, SEM_SIZE, SEM_PERMISSION);
    if (existing_sem_id > 0) {
        return existing_sem_id;
    }

    int sem_id = semget(SEM_KEY, SEM_SIZE, SEM_PERMISSION | IPC_CREAT);
    if (sem_id > 0) {
        return sem_id;
    }

    fprintf(stderr, "Unable to get semaphore");
    exit(1);
}

void semaphore_inc(int sem_num) {
    int sem_id = get_semaphore_set();
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"
    buf.sem_num = sem_num;
#pragma clang diagnostic pop
    buf.sem_op = 1;
    buf.sem_flg = 0;
    if (semop(sem_id, &buf, 1) == -1) {
        fprintf(stderr, "Unable to decrease semaphore with num: %d", sem_num);
        exit(1);
    }
}

void semaphore_dec(int sem_num) {
    int sem_id = get_semaphore_set();
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"
    buf.sem_num = sem_num;
#pragma clang diagnostic pop
    buf.sem_op = -1;
    buf.sem_flg = 0;
    if (semop(sem_id, &buf, 1) == -1) {
        fprintf(stderr, "Unable to decrease semaphore with num: %d", sem_id);
        exit(1);
    }
}

