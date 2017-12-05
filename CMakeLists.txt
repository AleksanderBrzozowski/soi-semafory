cmake_minimum_required(VERSION 3.9)
project(semafory_soi C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES semaphore.c semaphore.h buffer.c buffer.h shared_memory.c shared_memory.h)

add_executable(init ${SOURCE_FILES} init.c)
add_executable(producer_a ${SOURCE_FILES} producer_a.c)
add_executable(producer_b ${SOURCE_FILES} producer_b.c)
add_executable(consumer ${SOURCE_FILES} consumer.c)
