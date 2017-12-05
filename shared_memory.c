//
// Created by abrzozowski on 05.12.17.
//

#include <stddef.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include "shared_memory.h"

int get_shared_memory(size_t size) {
    int existing_shm_id = shmget(SHM_KEY, size, SHM_PERMISSION);
    if (existing_shm_id > 0) {
        return existing_shm_id;
    }

    int shm_id = shmget(SHM_KEY, size, SHM_PERMISSION | IPC_CREAT);
    if (shm_id > 0) {
        return shm_id;
    }

    fprintf(stderr, "Unable to get shared memory");
    exit(1);
}

