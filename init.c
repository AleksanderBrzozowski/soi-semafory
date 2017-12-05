//
// Created by abrzozowski on 04.12.17.
//

#include <stdio.h>
#include "semaphore.h"
#include "buffer.h"

int main() {
    buffer_init();
    fprintf(stdout, "Init buffer finished");
    return 0;
}
