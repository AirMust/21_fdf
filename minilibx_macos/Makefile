# #
# #

# APP = mlx_app
# NAME = libmlx.a

# .PHONY: clean fclean all re

# SRCS = mlx_shaders.c
# SRCS += mlx_new_window.c
# SRCS += mlx_init_loop.c
# SRCS += mlx_new_image.c
# SRCS += mlx_xpm.c
# SRCS += mlx_int_str_to_wordtab.c

# OBJM = $(SRCS:.c=.o)
# OBJECTS_MLX = $(OBJS:.m=.o)

# all : $(NAME) Makefile
# 	# echo "Project $(NAME) build successfully \c" >> tmp.log

# $(NAME): $(OBJECTS_MLX)
# 	ar -r  $(NAME) $(OBJECTS_MLX)
# 	ranlib $(NAME)
# 	# echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m\n"

# clean:
# 	rm -f $(NAME) $(OBJECTS_MLX) *~
# 	rm -f ${APP}

# re: clean all

NAME = libmlx.a

SRCS = mlx_shaders.c
SRCS += mlx_new_window.c
SRCS += mlx_init_loop.c
SRCS += mlx_new_image.c
SRCS += mlx_xpm.c
SRCS += mlx_int_str_to_wordtab.c

ODIR = obj
OBJ1 = $(SRCS:.c=.o)

OBJECTS_MLX = $(OBJ1:.m=.o)
all: $(NAME) Makefile

$(NAME):	$(OBJECTS_MLX)
	@ar -r $(NAME) ${OBJECTS_MLX} > tmp.log
	@ranlib $(NAME) > tmp.log

clean:
	rm -f $(NAME) $(OBJECTS_MLX) *~
	rm -f mlx_app

re: clean all
