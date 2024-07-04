##
## EPITECH PROJECT, 2024
## B-ASM-400-BDX-4-1-bsasmminilibc-marius.marolleau
## File description:
## Makefile
##

ASM = nasm

NAME = libasm.so

SRC = strlen.asm\
	  strcmp.asm\
	  strncmp.asm\
	  strchr.asm\
	  strrchr.asm\
	  strstr.asm\
	  strcspn.asm\
	  strpbrk.asm\
	  memcpy.asm\
	  memset.asm\
	  memmove.asm\
	  strcasecmp.asm\

OBJ = $(SRC:.asm=.o)

LDFLAGS = -f elf64 -g -F dwarf

all : $(NAME)

$(NAME) : $(OBJ)
		ld -shared -o $(NAME) $(OBJ)

%.o : %.asm
		$(ASM) $(LDFLAGS) -o $@ $<


clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all name
