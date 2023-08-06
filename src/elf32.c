#include "nm.h"

void die(int fd) {
    printf("Error\n");
    close(fd);
}

void handle_elf32() {
    printf("32-bit format\n");
}