# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: air_must <air_must@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 14:04:51 by slynell           #+#    #+#              #
#    Updated: 2020/11/12 05:46:54 by air_must         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

FLAGS = -Wall -Werror -Wextra
# -Wall -Werror -Wextra -O2


# /*
# ** ========================== HEADER ==============================
# */
INCS = fdf.h
IDIR = header
LDIR = libft
INCS += $(addprefix $(LDIR)/,$(addprefix $(IDIR)/,$(libft.h)))
INCLUDES = $(addprefix $(IDIR)/,$(INCS))

LIBFT = $(addprefix $(LDIR)/,libft.a)

# ** ========================== MLX =================================
MLXA := libmlx.a
MLX_DIR := ./minilibx_macos
MLX_LIBS  = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# /*
# ** ====================== SOURCE LS MAIN ==========================
# */
SDIR = src
ODIR = obj

SRCS = main.c
SRCS += fdf_error.c
SRCS += fdf_img_utils.c
SRCS += fdf_line_utils.c
# SRCS += lemin_create.c
# SRCS += lemin_error.c
# SRCS += lemin_read.c
# SRCS += lemin_free.c
# SRCS += lemin_path.c
# SRCS += lemin_ants.c
# SRCS += algo_apply.c
# SRCS += algo_help_1.c
# SRCS += algo_help_2.c
# SRCS += lemin_print.c
# SRCS += lemin_print_help.c
# SRCS += lemin_rooms.c
# SRCS += print_test.c


SOURCES = $(addprefix $(SDIR)/,$(SRCS))
OBJECTS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))


.PHONY: clean fclean all re $(LIBFT)

all : $(NAME) Makefile
	@2> tmp.log
	@@echo "Project $(NAME) build successfully \c" >> tmp.log

$(NAME) : $(LIBFT) $(MLX) $(OBJECTS)  $(INCLUDES)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -I $(IDIR) $(LIBFT) $(MLX_LIBS)
	@echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m\n"

# /*
# ** ====================== MAKE LIBFT ==========================
# */
$(LIBFT) : Makefile
	@make -C $(LDIR) 2> tmp.log

# /*
# ** ====================== MAKE MLX =============================
# */
$(MLX) : Makefile
	@make -C $(MLX_DIR) all --silent > tmp.log

# /*
# ** ====================== SOURCE LS MAIN  ==========================
# */
$(ODIR)/%.o : $(SDIR)/%.c $(INCLUDES)
	@if [[ $< == src/main.c ]]; then \
		echo "Make \033[33m$(NAME)\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR) 2> tmp.log
	@$(CC) $(FLAGS) -I $(IDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


clean:
	@make clean -C $(LDIR) 2> tmp.log
	@rm -rf $(OBJS) 2> tmp.log
	@make -C $(MLX_DIR) clean --silent
	@rm -rf $(ODIR) 2> tmp.log

fclean: clean
	@make fclean -C $(LDIR) 2> tmp.log
	@rm -rf $(NAME) 2> tmp.log
	@rm -rf $(MLX_DIR)/$(MLXA)
	@echo "\033[31m> Clear $(NAME)\033[0m"

re: fclean all
