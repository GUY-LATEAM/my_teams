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
printf "$(BRED)[$(BPURPLE)RULE $(UPURPLE)$1$(NO_COLOR) : \
$(BGREEN)nothing to be done$(BRED)]\n$(NO_COLOR)"
endef

# ---------------------------------------------------------------------

COMPILATION	=	liblist.a

SRC	:=	init_list.c							\
		list_get_data.c						\
		add_to_list.c						\
		add_to_list_i.c						\
		remove_list.c
SRC	:=	$(addprefix src/,$(SRC))

SRC_TEST	:=	$(filter-out main.c,$(SRC))	\
				tests/tests.c

CFLAGS	=	-Wall -Wextra -Wpedantic -I./include/


RM_ARRAY	=	$(OBJ) *~ a.out *.gcno *.gcda unit_tests *\# \#*
FRM_ARRAY	=	$(RM_ARRAY) $(COMPILATION)

RM			:=	rm -rf

RULE = $(filter-out $@,$(MAKECMDGOALS))

# ---------------------------------------------------------------------

%.o: %.c
	@$(CC) $(CFLAGS) $^ -c -o $@
	@printf "$(BBLUE)[$(BLUE)builded$(BBLUE)] \
	$(NO_COLOR):$(BLUE) $@$(NO_COLOR)\n"

OBJ = $(SRC:.c=.o)

$(COMPILATION):	$(OBJ)
	@ar rc $(COMPILATION) $(OBJ)
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

test_run: CFLAGS += --coverage -lcriterion
test_run: fclean
	gcc -o unit_tests $(SRC_TEST) $(CFLAGS)
	./unit_tests
	gcovr --exclude tests/
