NAME = libmlx.a

SRCS = mlx_shaders.c
SRCS += mlx_new_window.c
SRCS += mlx_init_loop.c
SRCS += mlx_new_image.c
SRCS += mlx_xpm.c
SRCS += mlx_int_str_to_wordtab.c

OBJ1 = $(SRCS:.c=.o)

OBJECTS_MLX = $(OBJ1:.m=.o)
all: $(NAME) Makefile

$(NAME): $(OBJECTS_MLX) Makefile
	@echo "Make \033[33m$(NAME)\033[0m:\c"
	@ar -r $(NAME) $(OBJECTS_MLX) 2> tmp.log
	@ranlib $(NAME) 2> tmp.log
	@echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m\n"

# $(OBJECTS_MLX): $(OBJ1:.m=.o)
# 	@echo "\033[32m.\033[0m\c"
clean:
	@rm -f $(NAME) $(OBJECTS_MLX)
	@rm -f mlx_app

fclean: clean
	@echo "\033[31m> Clear $(NAME)\033[0m"

re: clean all
