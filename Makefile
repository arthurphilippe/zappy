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

LN		=	ln -v

RM		=	rm -vf

ifndef VERBOSE
	MAKEFLAGS	+=	--no-print-directory
endif

all: server ai graphical

server:
	@$(MAKE) -C $(SERVER_DIR)
	@$(LN) -f $(SERVER_DIR)/$(SERVER) ./

ai:
	@$(MAKE) -C $(AI_DIR)
	@$(LN) -f $(AI_DIR)/$(AI) ./

graphical:
	@$(MAKE) -C $(GRAPHICAL_DIR)
	@$(LN) -f $(GRAPHICAL_DIR)/$(GRAPHICAL) ./
	@$(LN) -sf $(GRAPHICAL_DIR)/assets/ ./

clean:
	@$(MAKE) clean -C $(SERVER_DIR)
	@$(MAKE) clean -C $(AI_DIR)
	@$(MAKE) clean -C $(GRAPHICAL_DIR)

fclean:
	@$(MAKE) fclean -C $(SERVER_DIR)
	@$(MAKE) fclean -C $(AI_DIR)
	@$(MAKE) fclean -C $(GRAPHICAL_DIR)
	@$(RM) $(SERVER)
	@$(RM) $(AI)
	@$(RM) $(GRAPHICAL)
	@$(RM) assets

re: fclean all

.PHONY: all server ai clean fclean re
