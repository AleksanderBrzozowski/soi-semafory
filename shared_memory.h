//
// Created by abrzozowski on 05.12.17.
//

#ifndef SEMAFORY_SOI_SHARED_MEMORY_H
#define SEMAFORY_SOI_SHARED_MEMORY_H

#define SHM_KEY         45201
#define SHM_PERMISSION  0600

int get_shared_memory(size_t size);

#endif //SEMAFORY_SOI_SHARED_MEMORY_H
