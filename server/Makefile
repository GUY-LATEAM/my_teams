##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

COMPILATION = my_teams_server

SRC_INIT 	:= 	init_channel.c \
			init_contexte.c \
			init_conversation.c \
			init_message.c \
			init_reply.c \
			init_server.c \
			init_teams.c \
			init_thread.c \
			init_user.c
SRC_INIT 	:= 	$(addprefix init/, $(SRC_INIT))

SRC_DESTROY 	:= 	destroy_channel.c \
			destroy_contexte.c \
			destroy_conversation.c \
			destroy_message.c \
			destroy_reply.c \
			destroy_server.c \
			destroy_team.c \
			destroy_thread.c \
			destroy_user.c
SRC_DESTROY 	:= 	$(addprefix destroy/, $(SRC_DESTROY))

SRC_CHECKS 	:= 	check_args_server.c
SRC_CHECKS 	:= 	$(addprefix checks/, $(SRC_CHECKS))

SRC_SERVER_LOGIC 	:= 	server_loop.c
SRC_SERVER_LOGIC 	:= 	$(addprefix server_logic/, $(SRC_SERVER_LOGIC))

SRC_SIGNALS 	:= 	handle_signal.c
SRC_SIGNALS 	:= 	$(addprefix signals/, $(SRC_SIGNALS))


SRC 	:=	main.c
SRC 	+=  $(SRC_INIT) $(SRC_DESTROY) $(SRC_CHECKS) $(SRC_SERVER_LOGIC) \
		$(SRC_SIGNALS)
SRC		:= $(addprefix src/, $(SRC))

CFLAGS	=	-Wall -Wextra -pedantic -I./include -I./libs/list_lib/include \
 -I./libs/network_lib/include -I./libs/circular_buffer_lib/include

LDFLAGS	=	-L ./libs -luuid -lall

RULE = $(filter-out $@,$(MAKECMDGOALS))

LIBRARY_PATHS = ./libs

# ------------------------------------------------------------------

OBJ = $(SRC:.c=.o)

%.o:		%.c
	@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)
	@echo -e "[\033[0;32mcompiled\033[0m] `printf '% 29s' $<`" | tr ' ' '.'

all: make_library $(COMPILATION)
ifneq (,$(wildcard $(COMPILATION)))
ifneq ($(RULE), re)
	@echo -e "[\033[1;32mAlready up to date\033[0m]"
endif
endif

$(COMPILATION): $(OBJ)
	@$(CC) $(OBJ) -o $(COMPILATION) $(LDFLAGS)
	@echo -e "[\033[0;36mbuilt\033[0m] `printf '% 32s' $(OBJ)`"
		@echo -e "[\033[1;93mBinary \033[1;32mcreated\033[0m] \
		 `printf '% 23s' $(COMPILATION)`" | tr ' ' '.'

make_library:
	@make $(RULE) -s -C $(LIBRARY_PATHS)

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
	@make -C -s $(LIBRARY_PATHS) clean
