##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## to compile project
##

SRC	=	$(shell find $(SRC_DIR) -name '*.c')

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -Wall -Wextra -lm -g3 -o $(NAME) $(OBJ) -l csfml-graphics	\
	-l csfml-window	-l csfml-system -l csfml-audio
	@echo [Compiled project]

clean:
	@rm -f src/*.o
	@rm -f src/*~
	@rm -f include/*~
	@rm -f vgc*

fclean:		clean
	@rm -f $(NAME)
	@echo [Repo clean!!!]

re:	fclean all
