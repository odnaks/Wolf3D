NAME = wolf3d
SRC = src/*.c
HEADERS = -Iincludes -I ~/Library/Frameworks/SDL2.framework/Versions/A/Headers
LINUX_LINKS = -L./libft -lft -lm -lpthread
SDL = -F ~/Library/Frameworks/ -framework SDL2
GFLAGS = -Wall -Wextra -Werror -Ofast

$(NAME):
	make -C libft
	gcc $(GFLAGS) $(SRC) $(HEADERS) $(LINUX_LINKS) $(SDL) -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f libft/*.o

fclean: clean
	/bin/rm -f libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all
