#include "nm.h"


void handle_elf64(t_file *file) {
    file->elf.class = ELF64;
    if (file->fd < 0) {
        printf("ft_nm: '%s': No such file\n", file->filename);
        return ;
    }
    file->elf.elf64_hdr = (Elf64_Ehdr*)file->elf.mapped_region;
    if (file->elf.elf64_hdr->e_ident[EI_MAG0] != 0x7f)
        printf("ft_nm: %s: file format not recognized\n", file->filename);
    else {
        printf("%c%c%c\n", file->elf.elf64_hdr->e_ident[EI_MAG1], file->elf.elf64_hdr->e_ident[EI_MAG2], file->elf.elf64_hdr->e_ident[EI_MAG3]);
    }
}