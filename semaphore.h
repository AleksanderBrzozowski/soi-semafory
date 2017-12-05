//
// Created by abrzozowski on 04.12.17.
//

#include <stddef.h>

#ifndef SEMAFORY_SOI_SEMAPHORE_H
#define SEMAFORY_SOI_SEMAPHORE_H

#define SEM_KEY         451996
#define SEM_PERMISSION  0600
#define SEM_SIZE        12

#define BUFF_FULL       0
#define BUFF_EMPTY      1
#define BUF2_FULL       2
#define BUF2_EMPTY      3
#define BUF1_A          4
#define BUF1_B          5
#define BUFF_MUTEX       6

int init_semaphore(unsigned int sem_num, unsigned int initial_value);

void semaphore_inc(int sem_id);

void semaphore_dec(int semid);

#endif //SEMAFORY_SOI_SEMAPHORE_H
