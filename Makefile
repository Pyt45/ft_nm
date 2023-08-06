NAME := ft_nm

CC := gcc
FLAGS := -Wall -Wextra -Werror
OBJDIR := obj/
SRCDIR := src/

SRC := main.c utils.c elf32.c elf64.c memory_mapping.c
OBJ := $(addprefix $(OBJDIR), $(SRC:.c=.o))
INCLUDE := include

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c $(INCLUDE)
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -I$(INCLUDE) -o $@ -c $<

clean:
	@rm -rf $(OBJDIR)
fclean: clean
	@rm -f $(NAME)

re: fclean all