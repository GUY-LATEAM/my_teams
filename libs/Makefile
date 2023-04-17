##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

LIB_NAME = liball.a

SRC_BUFF = circular_buffer_lib/src/cbuff_create.c \
           circular_buffer_lib/src/cbuff_destroy.c \
           circular_buffer_lib/src/cbuff_misc.c

SRC_LIST = list_lib/src/init_list.c \
           list_lib/src/list_get_data.c \
           list_lib/src/add_to_list.c \
           list_lib/src/add_to_list_i.c \
           list_lib/src/remove_list.c

SRC_LIBMATH	:=	my_compute_power_it.c				\
				my_compute_power_rec.c				\
				my_compute_square_root.c			\
				my_getfloat.c						\
				my_getnbr.c							\
				my_isneg.c							\
				my_put_nbr.c						\
				my_swap.c
SRC_LIBMATH	:= $(addprefix libmath/,$(SRC_LIBMATH))

SRC_LIBSTR	:=	check_char.c						\
				destroy_arr.c						\
				display_arr.c						\
				get_file.c							\
				get_file_no_stats.c					\
				is_same_str.c						\
				my_arraylen.c						\
				my_memset.c							\
				my_putchar.c						\
				my_puts.c							\
				my_puts_error.c						\
				my_putstr.c							\
				my_putstr_error.c					\
				my_revstr.c							\
				my_sort_int_array.c					\
				my_split.c							\
				my_split_left.c						\
				my_split_right.c					\
				my_strcapitalize.c					\
				my_strcat.c							\
				my_strcmp.c							\
				my_strcpy.c							\
				my_strdup.c							\
				my_str_isalpha.c					\
				my_str_islower.c					\
				my_str_isnum.c						\
				my_str_isprintable.c				\
				my_str_isupper.c					\
				my_strlen.c							\
				my_strlowcase.c						\
				my_strncmp.c						\
				my_strncpy.c						\
				my_strstr.c							\
				my_strupcase.c						\
				nbr_to_string.c						\
				pac.c								\
				str_to_word_array.c					\
				str_with.c
SRC_LIBSTR	:=	$(addprefix libstr/,$(SRC_LIBSTR))

SRC_MY_LIB	:=	$(SRC_LIBMATH) $(SRC_LIBSTR)
SRC_MY_LIB	:=	$(addprefix my_lib/,$(SRC_MY_LIB))

SRC_NETWORK = network_lib/src/client_create_func.c \
              network_lib/src/client_destroy_func.c \
              network_lib/src/client_misc_func.c \
              network_lib/src/select_func.c \
              network_lib/src/select_misc_func.c \
              network_lib/src/server_create_func.c \
              network_lib/src/server_destroy_func.c \
              network_lib/src/server_misc_func.c \
              network_lib/src/socket_basic_func.c \
              network_lib/src/socket_basic_extended_func.c \
              network_lib/src/socket_management.c \
              network_lib/src/socket_clear.c \
              network_lib/src/socket_manipulation.c

SRC = $(SRC_BUFF) $(SRC_LIST) $(SRC_NETWORK) $(SRC_MY_LIB)

CFLAGS = -Wall -Wextra -Wpedantic \
         -I./circular_buffer_lib/include/ \
         -I./list_lib/include/ \
         -I./network_lib/include/ \
         -I./my_lib/include/

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_NAME): $(OBJ)
	ar rc $(LIB_NAME) $(OBJ)
	@echo "$(LIB_NAME) créée."

all: $(LIB_NAME)

clean:
	rm -f $(OBJ) $(LIB_NAME)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all
