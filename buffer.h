//
// Created by abrzozowski on 05.12.17.
//

#ifndef SEMAFORY_SOI_BUFFER_H
#define SEMAFORY_SOI_BUFFER_H

#define BUFF_SIZE 20
typedef struct Buffer {
    char data[BUFF_SIZE];
    int size;
} Buffer;

void buffer_init();
void buffer_put(Buffer* buff, char value);
char buffer_pop(Buffer* buff);
Buffer* get_buff();


#endif //SEMAFORY_SOI_BUFFER_H
