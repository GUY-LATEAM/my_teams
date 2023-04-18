##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

# ---------------------------------COLOR-------------------------------

NO_COLOR	=	\033[0m
BLINK		=	\033[5m
BLUE		=	\033[0;34m
RED			=	\033[0;31m
PURPLE		=	\033[0;35m
BBLUE		=	\033[1;34m
BGREEN		=	\033[1;32m
BPURPLE		=	\033[1;35m
BRED		=	\033[1;31m
UGREEN		=	\033[4;32m
UPURPLE		=	\033[4;35m

# ---------------------------------DEFINE------------------------------

OK=$(BGREEN)$(BLINK)✔$(NO_COLOR)
KO=$(BGREEN)$(BLINK)X$(NO_COLOR)

define delete
$(foreach rm_var, $1, \
		$(if $(wildcard $(rm_var)), rm -f $(rm_var) && \
		printf "$(BRED)[$(RED)deleted$(BRED)] $(NO_COLOR)\
		:$(RED) $(rm_var)$(NO_COLOR)\n";) \
)
endef

define already_done
printf "$(BRED)[$(BPURPLE)RULE $(UPURPLE)$1$(NO_COLOR) : \
$(BGREEN)nothing to be done$(BRED)]\n$(NO_COLOR)"
endef

# ---------------------------------------------------------------------

COMPILATION = my_teams_server

SRC 	:=	main.c
SRC 	+= 	add/add_conversation_to_user.c \
			add/add_message_to_conversation.c \
			add/add_reply_to_thread.c \
			add/add_user_to_conversation.c \
			add/add_user_to_server.c \
			add/add_user_to_team.c \
			add/create_and_add_channel.c \
			add/create_and_add_reply.c \
			add/create_and_add_team.c \
			add/create_and_add_thread.c \
			init/init_channel.c \
			init/init_contexte.c \
			init/init_conversation.c \
			init/init_message.c \
			init/init_reply.c \
			init/init_server.c \
			init/init_teams.c \
			init/init_thread.c \
			init/init_user.c \
			destroy/destroy_channel.c \
			destroy/destroy_contexte.c \
			destroy/destroy_conversation.c \
			destroy/destroy_message.c \
			destroy/destroy_reply.c \
			destroy/destroy_server.c \
			destroy/destroy_team.c \
			destroy/destroy_thread.c \
			destroy/destroy_user.c \
			checks/check_args_server.c \
			server_logic/server_loop.c \
			server_logic/new_con_func.c \
			signals/handle_signal.c \
			save/server/load_channel.c \
			save/server/load_reply.c \
			save/server/load_server_from_file.c \
			save/server/load_team.c \
			save/server/load_thread.c \
			save/server/load_user.c \
			save/server/save_channel.c \
			save/server/save_reply.c \
			save/server/save_team.c \
			save/server/save_thread.c \
			save/user/load_conversation.c \
			save/user/load_message.c \
			save/user/load_user.c \
			save/user/load_users_from_file.c \
			save/user/save_conversation.c \
			save/user/save_message.c \
			save/user/save_user.c \
			save/free_token.c \
			save/save_server_data.c \
			save/server/save_server_to_file.c \
			save/user/save_users_to_file.c \
			save/str_split_utils.c \
			save/str_split.c \
			save/time_utils.c

SRC_COMMANDS :=	command_not_found/command_not_found.c	\
				create_command/create_command.c	\
				create_command/create_command_utils.c	\
				create_command/send_broadcast_create_command.c	\
				help_command/help_command.c		\
				info_command/info_command.c		\
				list_command/list_command.c		\
				login_command/login_command.c		\
				login_command/login_utils.c		\
				logout_command/logout_command.c	\
				messages_command/messages_command.c	\
				send_command/send_command_utils.c	\
				send_command/send_command.c		\
				subscribe_command/subscribe_command.c	\
				subscribed_command/subscribed_command.c	\
				unsubscribe_command/unsubscribe_command.c	\
				use_command/use_command.c		\
				use_command/get_context.c		\
				user_command/user_command.c		\
				users_command/users_command.c \
				broadcast/broadcast_all_users.c \
				broadcast/broadcast_teams.c \
				command_utils.c \
				find_user.c
SRC_COMMANDS	:=	$(addprefix commands/, $(SRC_COMMANDS))

SRC_RECEIVE	:=	receive_handler.c \
				disconnect_func.c
SRC_RECEIVE	:=	$(addprefix receive/, $(SRC_RECEIVE))

SRC 	+=	$(SRC_RECEIVE) $(SRC_COMMANDS)
SRC		:= $(addprefix src/, $(SRC))

CFLAGS	=	-Wall -Wextra -pedantic -I./include -I../libs/list_lib/include \
	-I../libs/network_lib/include -I../libs/circular_buffer_lib/include	\
	-I../libs/my_lib/include -I../libs/myteams

LDFLAGS	=	-L ../libs -lall -luuid -L../libs/myteams -lmyteams

RM_ARRAY	:=	*~ a.out *.gcno *.gcda unit_tests *\# \#*
FRM_ARRAY	=	$(RM_ARRAY) $(OBJ) $(COMPILATION)

RM			:=	rm -rf

RULE = $(filter-out $@,$(MAKECMDGOALS))

# ---------------------------------------------------------------------

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) -c -o $@ $< $(CFLAGS) $(LDFLAGS)
	@printf "$(BBLUE)[$(BLUE)builded$(BBLUE)] \
	$(NO_COLOR):$(BLUE) $@$(NO_COLOR)\n"

$(COMPILATION):	$(OBJ)
	@$(CC) $(OBJ) -o $(COMPILATION) $(LDFLAGS)
	@printf "\n$(BGREEN)$(COMPILATION)$(NO_COLOR)\
	 -> $(BGREEN)created $(OK)$(NO_COLOR)\n"

all: $(COMPILATION)

fclean:
ifneq (,$(wildcard $(FRM_ARRAY)))
	@$(call delete,$(FRM_ARRAY))
else
	@$(call already_done,$@)
endif


clean:
ifneq (,$(wildcard $(RM_ARRAY)))
	@$(call delete,$(RM_ARRAY))
else
	@$(call already_done,$@)
endif

re: fclean all

debug: CFLAGS += -g3
debug: fclean $(COMPILATION)
