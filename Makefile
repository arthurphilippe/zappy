SERVER	= zappy_server
SERVER_DIRECTORY = server

AI = zappy_ai
AI_DIRECTORY = ai

all: server ##ai

server:
	@make -C $(SERVER_DIRECTORY)
	@mv $(SERVER_DIRECTORY)/zappy_server ./

##ai:
##	make -C $(AI_DIRECTORY)
##	mv $(AI_DIRECTORY)/zappy_ai ./

clean:
	@make clean -C $(SERVER_DIRECTORY)
##	make clean -C $(AI_DIRECTORY)

fclean: clean
	$(RM) $(SERVER)
##	$(RM) $(AI)

re: fclean all

.PHONY: all server ai clean fclean re