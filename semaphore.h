//
// Created by abrzozowski on 04.12.17.
//

#include <stddef.h>

#ifndef SEMAFORY_SOI_SEMAPHORE_H
#define SEMAFORY_SOI_SEMAPHORE_H

#define SEM_KEY         45200
#define SEM_PERMISSION  0600
#define SEM_SIZE        6

#define SEM_BUFF_FULL       0
#define SEM_BUFF_EMPTY      1
#define SEM_BUFF_CAN_POP    2
#define SEM_BUFF_MUTEX      3
#define SEM_BUFF_PUT_A      4
#define SEM_BUFF_PUT_B      5

int set_semaphore_val(unsigned int sem_num, unsigned int initial_value);

void semaphore_inc(int sem_num);

void semaphore_dec(int sem_num);

#endif //SEMAFORY_SOI_SEMAPHORE_H
