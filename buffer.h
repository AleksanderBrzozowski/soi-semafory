//
// Created by abrzozowski on 05.12.17.
//

#ifndef SEMAFORY_SOI_BUFFER_H
#define SEMAFORY_SOI_BUFFER_H

#define BUFF_SIZE  20
#define BUFF_MIN   3
#define MAX_PREV_A 2
#define MAX_PREV_B 2


typedef struct Buffer {
    char data[BUFF_SIZE];
    int size;
    int prev_a_count;
    int prev_b_count;
} Buffer;

void buffer_init();
void buffer_put(Buffer* buff, char value);
char buffer_pop(Buffer* buff);
Buffer* get_buff();


#endif //SEMAFORY_SOI_BUFFER_H
