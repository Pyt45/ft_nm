#include "nm.h"


void handle_elf32(t_file *file) {
    printf("32-bit format\n");
    file->elf.class = ELF32;
    file->elf.elf32_hdr = (Elf32_Ehdr*)file->elf.mapped_region;
    printf("%c%c%c\n", file->elf.elf32_hdr->e_ident[EI_MAG1], file->elf.elf32_hdr->e_ident[EI_MAG2], file->elf.elf32_hdr->e_ident[EI_MAG3]);
}