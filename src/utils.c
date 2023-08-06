#include "nm.h"

t_file* new_file(int fd, const char *filename) {
    t_file* file;

    if ((file = (t_file *)malloc(sizeof(t_file)))) {
        file->fd = fd;
        t_pair pair = map_region(fd);
        file->elf.mapped_region = pair.ptr;
        file->filename = filename;
        file->size = pair.size;
        file->next = NULL;
    }
    return file;
}

void add_file(t_file **root, t_file *file) {
    t_file *tmp = *root;

    if (!*root) {
        *root = file;
        return ;
    }
    while (tmp && tmp->next)
        tmp = tmp->next;
    tmp->next = file;
}

void free_files(t_file **root) {
    t_file *tmp = *root;

    while (tmp) {
        t_file* prev = tmp;
        if (tmp->fd != -1)
            close(tmp->fd);
        if (tmp->elf.mapped_region != MAP_FAILED)
            munmap(tmp->elf.mapped_region, tmp->size);
        if (prev)
            free(prev);
        tmp = tmp->next;
    }
}