##
## EPITECH PROJECT, 2018
## nm
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -vf

NAME		=	zappy_server

MAIN		=	src/main.c

SRCS		=	src/list/list.c			\
			src/list/get.c			\
			src/list/iter.c			\
			src/list/pop.c			\
			src/list/push.c			\
			src/list/find.c			\
			src/stolist.c			\
			src/selector/create.c		\
			src/selector/delete.c		\
			src/selector/loop.c		\
			src/selector/get_new_handle.c	\
			src/handle/delete.c		\
			src/handle/client_create.c	\
			src/handle/client_erase.c	\
			src/handle/client_on_cycle.c	\
			src/handle/client_get_msgq.c	\
			src/handle/client_read.c	\
			src/handle/listener_create.c	\
			src/handle/listener_read.c	\
			src/game/create.c		\
			src/game/delete.c		\
			src/game/add_team.c		\
			src/game/register_player.c	\
			src/game/unreg_player.c		\
			src/game/take_object.c		\
			src/game/set_object.c		\
			src/player/create.c		\
			src/player/delete.c		\
			src/player/move.c		\
			src/player/turn.c		\
			src/player/read.c		\
			src/player/look.c		\
			src/player/inventory.c		\
			src/player/inventory_list.c	\
			src/team/create.c		\
			src/team/delete.c		\
			src/team/find.c			\
			src/board/create.c		\
			src/board/delete.c		\
			src/board/init.c		\
			src/board/get.c			\
			src/board/put.c			\
			src/board/look_at.c		\
			src/board/trunc_coords.c	\
			src/msg/process.c		\
			src/msg/process_cmd_pl.c	\
			src/msg/process_cmd_gfx.c	\
			src/msg/join.c			\
			src/msg/cmd_pl/set.c		\
			src/msg/cmd_pl/take.c		\
			src/msg/cmd_pl/broadcast.c	\
			src/msg/cmd_pl/forward.c	\
			src/msg/cmd_pl/right.c		\
			src/msg/cmd_pl/left.c		\
			src/msg/cmd_pl/look.c		\
			src/msg/cmd_pl/inventory.c	\
			src/parser/parser_arg_handler.c	\
			src/parser/parser_destroy.c	\
			src/parser/parser.c		\
			src/dynbuf/create.c		\
			src/dynbuf/init.c		\
			src/dynbuf/delete.c		\
			src/dynbuf/append.c		\
			src/dynbuf/reset.c		\
			src/resource.c			\
			src/start.c			\

OBJ_MAIN	=	$(MAIN:.c=.o)

OBJS		=	$(SRCS:.c=.o)

TEST		=	unit_tests.out

SRCS_TEST	=	tests/test-list.c	\
			tests/board.c		\
			tests/game.c		\
			tests/team.c		\
			tests/player.c		\
			tests/stolist.c		\
			tests/parser.c		\
			tests/resource.c	\
			tests/selector.c	\
			tests/dynbuf.c		\
			tests/handle/client.c	\

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

CFLAGS		=	-W -Wextra -Wall -Iinclude/

LDFLAGS		=

%.o: %.c
	@printf "[\033[0;36mcompiling\033[0m]% 39s\r" $< | tr " " "."
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mcompiled\033[0m]% 40s\n" $< | tr " " "."

all: $(NAME)

debug: CFLAGS += -ggdb
debug: fclean
debug: $(NAME)

tests: CFLAGS += -ggdb
tests: $(TEST) $(NAME)

tests_run: CC=gcc --coverage
tests_run: tests
	@./$(TEST) -j 1 --verbose --always-succeed
	@cd tests/ && find -name "*.gcda" -delete -o -name "*.gcno" -delete
	@cd src/ && rm -f main.gcda main.gcno

$(NAME): $(OBJ_MAIN) $(OBJS)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(NAME) | tr " " "."
	@$(CC) $(OBJ_MAIN) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(NAME) | tr " " "."

$(TEST): $(OBJS_TEST)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(TEST) | tr " " "."
	@$(CC) $(OBJS_TEST) -o $(TEST) $(LDFLAGS) -lcriterion
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(TEST) | tr " " "."

clean: artifacts_clean
	@printf "[\033[0;31mdeletion\033[0m][objects]% 31s\n" `$(RM) $(OBJ_MAIN) $(OBJS) $(OBJS_TEST) | wc -l | tr -d '\n'` | tr " " "."

fclean: clean
	@$(RM) $(NAME) $(TEST) > /dev/null
	@$(RM) $(TEST) > /dev/null
	@printf "[\033[0;31mdeletion\033[0m][binary]% 32s\n" $(NAME) | tr " " "."

artifacts_clean:
	@printf "[\033[0;31mdeletion\033[0m][artifacts]% 29s\n" `find -type f \( -name "*.gcno" -o -name "*.gc*" \) -delete -print | wc -l | tr -d '\n'` | tr " " "."

re: fclean all

.PHONY: all clean fclean re debug tests tests_run clean cov_clean
