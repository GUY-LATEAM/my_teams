##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile that gcc
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
printf "$(BRED)[$(BPURPLE)RULE $(UPURPLE)$1 | $(COMPILATION)$(NO_COLOR) : \
$(BGREEN)nothing to be done$(BRED)]\n$(NO_COLOR)"
endef

# ---------------------------------------------------------------------

COMPILATION = my_teams_cli

SRC 	:=	main.c \
			checks/check_args_client.c \
			client_logic/client_logic.c \
			destroy/destroy_client.c \
			destroy/destroy_context.c \
			init/init_client.c \
			init/init_context.c \
			init/init_client_protocol.c \
			signals/handle_signal.c \
			protocol_input/parse_input.c \
			protocol_input/read_input.c \
			protocol_input/manage_input.c \
			protocol_input/display_error.c \
			protocol_input/logic_input.c \
			protocol_input/use_logic.c \
			protocol_logic/receive_func.c \
			protocol_logic/manage_response.c \
			protocol_logic/parse_no_info_resp.c \

SRC		:= $(addprefix src/, $(SRC))

CFLAGS	=	-Wall -Wextra -pedantic -I./include -I../libs/list_lib/include \
	-I../libs/network_lib/include -I../libs/circular_buffer_lib/include

LDFLAGS	=	-L ../libs -lall -luuid

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
