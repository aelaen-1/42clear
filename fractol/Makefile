CCFLAGS = cc -Wall -Werror -Wextra -L 
MLXFLAGS = -Lmlx-linux -lmlx_Linux -lX11 -lXext

LIBFT = libft/
UTILS = utils/
NAME = fractol

all: $(NAME)

$(FRACTOL):
	$(MAKE) -C ./$(LIBFT)
	$(MAKE) -C ./minilibx-linux
	$(CCFLAGS) $(MLXFLAGS) ./*.c $(LIBFT) ./$(UTILS) ./$(LIBFT)/libft.a -o $(NAME)

clean:
	$(MAKE) clean -C ./$(LIBFT) ./$(UTILS)
	$(MAKE) clean -C ./minilibx-linux
	
fclean: clean
	$(MAKE) fclean -C ./$(LIBFT) ./$(UTILS)
	rm -f $(FRACTOL)

re: fclean all

.PHONY: all clean fclean re
