##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile that gcc
##

COMPILATION = my_teams

SRC 	:=	main.c
SRC		:= $(addprefix src/, $(SRC))

SRC_TEST	=	$(filter-out main.c,$(SRC))

CFLAGS	=	-Wall -Wextra -pedantic -I./include -I./libs/list_lib/include -I./libs/network_lib/include -I./libs/circular_buffer_lib/include

LDFLAGS	=	-L ./libs/list_lib -l list -L ./libs/network_lib -l network -L ./libs/circular_buffer_lib -l circular_buffer

RULE = $(filter-out $@,$(MAKECMDGOALS))

LIBRARY_PATHS = $(addprefix ./libs/, list_lib network_lib circular_buffer_lib)

# ------------------------------------------------------------------

OBJ = $(SRC:.c=.o)

%.o:		%.c
	@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)
	@printf "[\033[0;32mcompiled\033[0m] % 29s\n" $< |  tr ' ' '.'

all: make_library $(COMPILATION)
ifneq (,$(wildcard $(COMPILATION)))
ifneq ($(RULE), re)
	@printf "[\033[1;32mAlready up to date\033[0m]\n"
endif
endif

$(COMPILATION): $(OBJ)
	@$(CC) $(OBJ) -o $(COMPILATION)
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(OBJ) | tr ' ' '.'
	@printf "[\033[1;93mBinary \033[1;32mcreated\
	\033[0m] % 23s\n" $(COMPILATION) | tr ' ' '.'

make_library:
	@$(shell $(foreach lib, $(LIBRARY_PATHS), make $(RULE) -C $(lib) &&) true)

clean: make_library
	@$(RM) -f *~ *.gcno *.gcda *.gcda *.swn *.swo *.c.swp
	@$(RM) -f 'a.out'
	@$(RM) -f 'unit_tests'
ifneq (,$(wildcard ./$(OBJ)))
	@$(RM) -f $(OBJ)
	@printf "[\033[1;31mDeleted\033[0m] % 32s\n" $(OBJ) | tr ' ' '.'
else
	@printf "[\033[1;36mOBJ \033[1;32malready deleted\033[0m]\n"
endif

fclean : make_library clean
ifneq (,$(wildcard ./$(COMPILATION)))
	@rm -f $(COMPILATION)
	@printf "[\033[1;93mBinary \033[1;31mdeleted\
	\033[0m] % 25s\n" $(COMPILATION) | tr ' ' '.'
else
	@printf "[\033[1;93mBinary \033[1;32malready deleted\033[0m]\n"
endif

re: make_library fclean all

debug: CFLAGS += -g3
debug: RULE = re
debug:	make_library re

noice: RULE = re
noice: make_library re
	$(MAKE) clean
	@make -C $(LIBRARY_PATHS) clean
