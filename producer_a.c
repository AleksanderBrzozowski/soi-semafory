//
// Created by abrzozowski on 05.12.17.
//

#include <unistd.h>
#include "buffer.h"

int main() {
    Buffer *const pBuffer = get_buff();

    while (1) {
        sleep(2);
        buffer_put(pBuffer, 'A');
    }

    return 0;
}
