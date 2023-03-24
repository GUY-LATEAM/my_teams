##
## EPITECH PROJECT, 2023
## bs_teams
## File description:
## Makefile
##

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2
AR = ar
ARFLAGS = rcs

SRCS = sources/network_circular_buffer.c
OBJS = $(SRCS:.c=.o)
LIB = libmylib.a

all: $(LIB)

$(LIB): $(OBJS)
    $(AR) $(ARFLAGS) $@ $^

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re
