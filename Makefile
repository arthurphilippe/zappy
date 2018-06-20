##
## EPITECH PROJECT, 2018
## server
## File description:
## Makefile
##

SERVER		=	zappy_server
SERVER_DIR	=	server

AI		=	zappy_ai
AI_DIR		=	player

GRAPHICAL	=	ZappyGi
GRAPHICAL_DIR	=	graphics

# ifndef VERBOSE
# 	MAKEFLAGS	+=	--no-print-directory
# endif

all: server ai graphical

server:
	@$(MAKE) -C $(SERVER_DIR)
	@ln -f $(SERVER_DIR)/$(SERVER) ./

ai:
	@$(MAKE) -C $(AI_DIR)
	@ln -f $(AI_DIR)/$(AI) ./

graphical:
	@$(MAKE) -C $(GRAPHICAL_DIR)
	@ln -f $(GRAPHICAL_DIR)/$(GRAPHICAL) ./

clean:
	@$(MAKE) clean -C $(SERVER_DIR)
	@$(MAKE) clean -C $(AI_DIR)
	@$(MAKE) clean -C $(GRAPHICAL_DIR)

fclean:
	@$(MAKE) fclean -C $(SERVER_DIR)
	@$(MAKE) fclean -C $(AI_DIR)
	@$(MAKE) fclean -C $(GRAPHICAL_DIR)
	$(RM) $(SERVER)
	$(RM) $(AI)

re: fclean all

.PHONY: all server ai clean fclean re
