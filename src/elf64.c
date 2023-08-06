#include "nm.h"


void handle_elf64(t_file *file) {
    printf("64-bit format\n");
    file->elf.class = ELF64;
    file->elf.elf64_hdr = file->elf.mapped_region;
    printf("%c%c%c\n", file->elf.elf64_hdr->e_ident[EI_MAG1], file->elf.elf64_hdr->e_ident[EI_MAG2], file->elf.elf64_hdr->e_ident[EI_MAG3]);
    file->elf.elf64_shdr = (Elf64_Shdr *)(file->elf.mapped_region + file->elf.elf64_hdr->e_shoff);
    for (size_t i = 0; i < file->elf.elf64_hdr->e_shnum; i++) {
    //     // if (file->elf.elf64_shdr[i].sh_type == SHT_SYMTAB) {
    //     //     printf("static symbol table\n");
    //     //     // Elf64_Sym	*elf64_sym = (Elf64_Sym *)(file->elf.mapped_region + file->elf.elf64_shdr[i].sh_offset);
    //     //     // Elf64_Sym	*elf64_sym_end = (Elf64_Sym *)((char *)elf64_sym + file->elf.elf64_shdr[i].sh_size);
    //     //     // printf("|%s|\n", (char *)(file->elf.mapped_region + file->elf.elf64_shdr[file->elf.elf64_shdr[i].sh_link].sh_offset));
    //     // }
    //     // if (file->elf.elf64_shdr[i].sh_type == SHT_DYNSYM) {
    //     //     printf("dynamic symbol table\n");
    //     // }
    //     if (file->elf.elf64_shdr[i].sh_type == SHT_STRTAB) {
    //         printf("%d\n", file->elf.elf64_hdr->e_shstrndx);
    //     }
        Elf64_Shdr* elf64_shdr = &file->elf.elf64_shdr[i];
        // int symaddr = (int)file->elf.elf64_hdr + elf64_shdr->sh_offset;

        // Elf64_Sym* symbol = (Elf64_Sym*)(file->elf.elf64_hdr + elf64_shdr->sh_offset);
        // if (symbol->st_shndx == SHN_UNDEF) {
        //     Elf64_Shdr* strtab = (Elf64_Shdr *)(file->elf.elf64_hdr + elf64_shdr->sh_link);
        //     const char* name = (const char *)file->elf.elf64_hdr + strtab->sh_offset + symbol->st_name;
        //     printf("%s\n", "hey");
        // }
    }
    // Elf64_Shdr *hdr_table = &file->elf.elf64_shdr[file->elf.elf64_hdr->e_shstrndx];

    // const char* str_table = (const char*)(file->elf.mapped_region + hdr_table->sh_offset);
    // for (unsigned short i = 0; i < file->elf.elf64_hdr->e_shnum; i++) {
    //     printf("[%2d] %s\n", i, str_table + file->elf.elf64_shdr[i].sh_name);
    // }
} 