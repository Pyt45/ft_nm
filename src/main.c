#include "nm.h"

int main(int argc, char **argv) {
    int     fd;
    t_file  *file = NULL;

    if (argc == 1) {
        fd = open("a.out", O_RDONLY);
        if (fd < 0) {
            printf("ft_nm: 'a.out': No such file\n");
            exit(1);
        }
        file = new_file(fd, "a.out");
    }
    else {
        int i = 1;
        while (i < argc) {
            fd = open(argv[i], O_RDONLY);
            add_file(&file, new_file(fd, argv[i]));
            i++;
        }
    }
    t_file* tmp = file;
    while (tmp) {
        handle_elf(tmp);
        tmp = tmp->next;
    }
    printf("freeing\n");
    if (file)
        free_files(&file);
}