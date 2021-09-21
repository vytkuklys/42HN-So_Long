# -*- MakeFile -*-

FRAMEWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=so_long
SRC=src/*.c
INCLUDES=gnl/gnl.a minilibx/libmlx.a

all:
	@make -C gnl/ all
	@make -C minilibx/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAMEWORKS)

clean:
	@make -C gnl/ clean
	@make -C minilibx/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C gnl/ fclean

re: fclean all
