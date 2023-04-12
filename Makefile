##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

RULE = $(filter-out $@,$(MAKECMDGOALS))

LIBRARY_PATHS = ./libs

all: make_library server client

server:
	@make -s -C server $(RULE)
	@cp server/my_teams_server .

client:
	@make -s -C client $(RULE)
	@cp client/my_teams_cli .

clean: make_library clean_server clean_client

clean_server:
	@make -s -C server clean

clean_client:
	@make -s -C client clean

fclean: make_library clean
	@make -s -C server fclean
	@make -s -C client fclean
	@rm -f my_teams_server
	@rm -f my_teams_cli

re: fclean all

debug: make_library debug_server debug_client

debug_server:
	@make -s -C server debug
	@cp server/my_teams_server .

debug_client:
	@make -s -C client debug
	@cp client/my_teams_cli .

noice: noice_server noice_client

noice_server:
	@make -s -C server noice
	@cp server/my_teams_server .

noice_client:
	@make -s -C client noice
	@cp client/my_teams_cli .


make_library:
	@make $(RULE) -s -C $(LIBRARY_PATHS)

.PHONY: all server client clean clean_server clean_client fclean re debug \
 debug_server debug_client noice noice_server noice_client make_library
