#include "nm.h"

int verify_elf(int m, int e, int l, int f) {
    return m != 0x7f || e != 'E' || l != 'L' || f != 'F';
}

void handle_elf(t_file *file) {
    if (file->fd < 0) {
        printf("ft_nm: '%s': No such file\n", file->filename);
        return ;
    }
    file->elf.elf64_hdr = (Elf64_Ehdr*)file->elf.mapped_region;
    if (verify_elf(file->elf.elf64_hdr->e_ident[EI_MAG0],
            file->elf.elf64_hdr->e_ident[EI_MAG1],
            file->elf.elf64_hdr->e_ident[EI_MAG2],
            file->elf.elf64_hdr->e_ident[EI_MAG3]))
        printf("ft_nm: %s: file format not recognized\n", file->filename);
    else
        file->elf.elf64_hdr->e_ident[EI_CLASS] == 1 ? handle_elf32(file) : handle_elf64(file);
}