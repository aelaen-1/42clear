CC = cc
CFLAGS = -Wall -Werror -Wextra -L 
MLXFLAGS = -Lmlx-linux -lmlx_Linux -lX11 -lXext

FTLP = libft/
UTILS = utils/
FTFRACTOL = fractol.c
FRACTOL = fractol

all: $(FRACTOL)

$(FRACTOL):
	$(MAKE) -C ./$(FTLP)
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(FTLP) ./*.c ./$(UTILS) ./$(FTLP)/libft.a $(MLXFLAGS) -o $(FRACTOL)

clean:
	$(MAKE) clean -C ./$(FTLP) ./$(UTILS)
	$(MAKE) clean -C ./minilibx-linux
	
fclean: clean
	$(MAKE) fclean -C ./$(FTLP) ./$(UTILS)
	rm -f $(FRACTOL)

re: fclean all

.PHONY: all clean fclean re
