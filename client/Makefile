##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile that gcc
##

COMPILATION = my_teams_cli

SRC 	:=	main.c \
			./src/checks/check_args_client.c \
			./src/client_logic/client_logic.c \
			./src/destroy/destroy_client.c \
			./src/destroy/destroy_context.c \
			./src/init/init_client.c \
			./src/init/init_context.c \
			./src/signals/handle_signal.c \
			


SRC		:= $(addprefix src/, $(SRC))

CFLAGS	=	-Wall -Wextra -pedantic -I./include

RULE = $(filter-out $@,$(MAKECMDGOALS))

# ------------------------------------------------------------------

OBJ = $(SRC:.c=.o)

%.o:		%.c
	@$(CC) -c -o $@ $< $(CFLAGS)
	@echo -e "[\033[0;32mcompiled\033[0m] `printf '% 29s' $<`" | tr ' ' '.'

all: make_library $(COMPILATION)
ifneq (,$(wildcard $(COMPILATION)))
ifneq ($(RULE), re)
	@echo -e "[\033[1;32mAlready up to date\033[0m]"
endif
endif

$(COMPILATION): $(OBJ)
	@$(CC) $(OBJ) -o $(COMPILATION)
	@echo -e "[\033[0;36mbuilt\033[0m] `printf '% 32s' $(OBJ)`"
		@echo -e "[\033[1;93mBinary \033[1;32mcreated\033[0m] \
		 `printf '% 23s' $(COMPILATION)`" | tr ' ' '.'

make_library:
	@$(foreach lib, $(LIBRARY_PATHS), make $(RULE) -s -C $(lib);)

clean: make_library
	@$(RM) -f *~ *.gcno *.gcda *.gcda *.swn *.swo *.c.swp
	@$(RM) -f 'a.out'
	@$(RM) -f 'unit_tests'
ifneq (,$(wildcard ./$(OBJ)))
	@$(RM) -f $(OBJ)
	@echo -e "[\033[1;31mDeleted\033[0m] `printf '% 32s' $(OBJ)`" | tr ' ' '.'
else
	@echo -e "[\033[1;36mOBJ \033[1;32malready deleted\033[0m]"
endif

fclean : make_library clean
ifneq (,$(wildcard ./$(COMPILATION)))
	@rm -f $(COMPILATION)
	@echo -e "[\033[1;93mBinary \033[1;31mdeleted\033[0m] \
	 `printf '% 25s' $(COMPILATION)`" | tr ' ' '.'
else
	@echo -e "[\033[1;93mBinary \033[1;32malready deleted\033[0m]"
endif

re: make_library fclean all

debug: CFLAGS += -g3
debug: RULE = re
debug:	make_library re

noice: RULE = re
noice: make_library re
	$(MAKE) clean
	@make -C -s clean
