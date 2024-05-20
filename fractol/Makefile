CC = cc
CFLAGS = -Wall -Werror -Wextra -L 
MLXFLAGS = -Lmlx-linux -lmlx_Linux -lX11 -lXext

LIBFT = libft/
UTILS = utils/
FTFRACTOL = fractol.c
FRACTOL = fractol

all: $(FRACTOL)

$(FRACTOL):
	$(MAKE) -C ./$(LIBFT)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(FTLP) ./*.c ./$(UTILS) ./$(LIBFT)/libft.a $(MLXFLAGS) -o $(FRACTOL)

clean:
	$(MAKE) clean -C ./$(LIBFT) ./$(UTILS)
	$(MAKE) clean -C ./minilibx-linux
	
fclean: clean
	$(MAKE) fclean -C ./$(LIBFT) ./$(UTILS)
	rm -f $(FRACTOL)

re: fclean all

.PHONY: all clean fclean re
