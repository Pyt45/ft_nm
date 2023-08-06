#ifndef NM_H
# define NM_H

#include <stdio.h>
#include <sys/file.h>
# ifdef __aarch64__
#include "elf.h"
#else
#include <elf.h>
#endif
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/mman.h>


typedef enum	s_class {
    ELF32 = 1,
    ELF64 = 2,
}				t_class;

typedef struct	s_pair {
	size_t		size;
	void		*ptr;
}				t_pair;

typedef struct s_symbol {
	Elf64_Sym	*elf64_sym;
	Elf32_Sym	*elf32_sym;
}				t_symbol;

typedef struct	s_elf {
	void		*mapped_region;
	t_class		class;
	Elf64_Ehdr	*elf64_hdr;
	Elf32_Ehdr	*elf32_hdr;
	Elf64_Shdr	*elf64_shdr;
	Elf32_Shdr	*elf32_shdr;
}              t_elf;

typedef struct		s_file {
	const char		*filename;
	int				fd;
	size_t			size;
	t_elf			elf;
	struct s_file	*next;
}					t_file;
int verify_elf(int m, int e, int l, int f);
t_file* new_file(int fd, const char *filename);
void add_file(t_file **root, t_file *file);
void free_files(t_file **root);

t_pair map_region(int fd);
void handle_elf32(t_file *file);
void handle_elf64(t_file *file);
void handle_elf(t_file *file);

#endif