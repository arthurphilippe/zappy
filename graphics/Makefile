##
## EPITECH PROJECT, 2018
## nanotekspice
## File description:
## Makefile
##

CXX		=	g++

NAME		=	ZappyGi

RM		=	rm -vf

MAIN		=	src/main.cpp

SRCS		=	src/Socket.cpp		\
			src/Parser.cpp		\
			src/Display.cpp		\
			src/Item.cpp		\
			src/ParserEngine.cpp	\
			src/BackgroundMap.cpp	\
			src/Command.cpp		\
			src/Core.cpp		\
			src/Server.cpp		\

OBJ_MAIN	=	$(MAIN:.cpp=.o)

OBJS		=	$(SRCS:.cpp=.o)

TEST		=	unit_tests.out

SRCS_TEST	=	tests/socket.cpp		\
			tests/parser.cpp		\
			tests/parserengine.cpp		\
			# tests/backgroundMap.cpp		\

SRCS_TEST	+=	$(OBJS)

OBJS_TEST	=	$(SRCS_TEST:.cpp=.o)

CPPFLAGS	=	-W -Wextra -Wall -Isrc/ -std=c++17

LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

%.o: %.cpp
	@printf "[\033[0;36mcompiling\033[0m]% 39s\r" $< | tr " " "."
	@$(CXX) -c -o $@ $< $(CPPFLAGS)
	@printf "[\033[0;32mcompiled\033[0m]% 40s\n" $< | tr " " "."

all: $(NAME)

debug: CPPFLAGS += -ggdb
# debug: fclean
debug: $(NAME)

tests: CXX=g++
tests: $(TEST)

tests_run: CXX=g++
tests_run: CPPFLAGS += --coverage -I../src/
tests_run: LDFLAGS += -lgcov
tests_run: $(TEST)
	@./$(TEST) --verbose -j 1 --always-succeed
#	@cd tests/ && find -name "*.gcda" -delete -o -name "*.gcno" -delete
	@cd src/ && rm -f main.gcda main.gcno

$(NAME): $(OBJ_MAIN) $(OBJS)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(NAME) | tr " " "."
	@$(CXX) $(OBJ_MAIN) $(OBJS) -o $(NAME) $(LDFLAGS)
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(NAME) | tr " " "."

$(TEST): $(OBJS_TEST)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(TEST) | tr " " "."
	@$(CXX) $(OBJS_TEST) -o $(TEST) -lcriterion $(LDFLAGS)
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(TEST) | tr " " "."

clean: artifacts_clean
	@printf "[\033[0;31mdeletion\033[0m][objects]% 31s\n" `$(RM) $(OBJ_MAIN) $(OBJS) $(OBJS_TEST) | wc -l | tr -d '\n'` | tr " " "."

fclean: clean
	@$(RM) $(NAME) $(TEST) > /dev/null
	@printf "[\033[0;31mdeletion\033[0m][binary]% 32s\n" $(NAME) | tr " " "."

artifacts_clean:
	@printf "[\033[0;31mdeletion\033[0m][artifacts]% 29s\n" `find -type f \( -name "*.gcno" -o -name "*.gc*" \) -delete -print | wc -l | tr -d '\n'` | tr " " "."

re: fclean all

.PHONY: all clean fclean re debug tests artifacts_clean ui
