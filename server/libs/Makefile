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

SRC_NETWORK = network_lib/src/client_create_func.c \
              network_lib/src/client_destroy_func.c \
              network_lib/src/client_misc_func.c \
              network_lib/src/select_func.c \
              network_lib/src/server_create_func.c \
              network_lib/src/server_destroy_func.c \
              network_lib/src/server_misc_func.c \
              network_lib/src/socket_basic_func.c \
              network_lib/src/socket_basic_extended_func.c \
              network_lib/src/socket_management.c \
              network_lib/src/socket_manipulation.c

SRC = $(SRC_BUFF) $(SRC_LIST) $(SRC_NETWORK)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Wpedantic \
         -I./circular_buffer_lib/include/ \
         -I./list_lib/include/ \
         -I./network_lib/include/

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar rc $(LIB_NAME) $(OBJ)
	@echo "$(LIB_NAME) créé."

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(LIB_NAME)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all
