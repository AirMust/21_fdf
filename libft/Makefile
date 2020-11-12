# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcaterpi <vcaterpi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 11:23:23 by slynell           #+#    #+#              #
#    Updated: 2020/10/22 19:17:21 by vcaterpi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SDIR = src

ODIR = obj

HDIR = header

HEAD = libft.h
HEAD += macros.h
HEAD += ft_printf.h
HEAD += ft_printf_const_data.h
HEAD += ft_printf_errors.h

# /*
# ** ====================== SOURCE OTHER ==========================
# */
SDIR_OTHER = src/ft_other
ODIR_OTHER = obj/ft_other

SRC_OTHER = ft_atoill.c
SRC_OTHER += ft_abs.c
SRC_OTHER += ft_atoi.c
SRC_OTHER += ft_check_integer.c
SRC_OTHER += ft_divmod.c
SRC_OTHER += ft_intlen.c
SRC_OTHER += ft_isalnum.c
SRC_OTHER += ft_isalpha.c
SRC_OTHER += ft_isascii.c
SRC_OTHER += ft_isdigit.c
SRC_OTHER += ft_isprint.c
SRC_OTHER += ft_itoa.c
SRC_OTHER += ft_long_pow.c
SRC_OTHER += ft_longlen.c
SRC_OTHER += ft_pow.c
SRC_OTHER += ft_tolower.c
SRC_OTHER += ft_toupper.c
SRC_OTHER += ft_uitoa_base.c
SRC_OTHER += ft_uitoa_dec.c
SRC_OTHER += ft_uitoa_hex.c
SRC_OTHER += ft_ultoa_base.c
SRC_OTHER += ft_ultoa_hex.c
SRC_OTHER += ft_wstrlen.c
SRC_OTHER += ft_countwords.c
SRC_OTHER += ft_checkoverflow.c
SRC_OTHER += ft_is_number.c
SOURCES_OTHER = $(addprefix $(SDIR_OTHER)/,$(SRC_OTHER))
OBJECTS_OTHER = $(addprefix $(ODIR_OTHER)/,$(SRC_OTHER:.c=.o))

# /*
# ** ====================== SOURCE MEMORY ==========================
# */
SDIR_MEMORY = src/ft_memory
ODIR_MEMORY = obj/ft_memory

SRC_MEMORY = ft_memalloc.c
SRC_MEMORY += ft_memccpy.c
SRC_MEMORY += ft_memchr.c
SRC_MEMORY += ft_memcmp.c
SRC_MEMORY += ft_memcpy.c
SRC_MEMORY += ft_memcpy.c
SRC_MEMORY += ft_memdel.c
SRC_MEMORY += ft_memmove.c
SRC_MEMORY += ft_memset.c
SRC_MEMORY += ft_memswap.c
SRC_MEMORY += ft_bzero.c

SOURCES_MEMORY = $(addprefix $(SDIR_MEMORY)/,$(SRC_MEMORY))
OBJECTS_MEMORY = $(addprefix $(ODIR_MEMORY)/,$(SRC_MEMORY:.c=.o))


# /*
# ** ====================== SOURCE PUT ==========================
# */
SDIR_PUT = src/ft_put
ODIR_PUT = obj/ft_put

SRC_PUT = ft_putchar.c
SRC_PUT += ft_putchar_fd.c
SRC_PUT += ft_putendl.c
SRC_PUT += ft_putendl_fd.c
SRC_PUT += ft_putnbr.c
SRC_PUT += ft_putnbr_fd.c
SRC_PUT += ft_putstr.c
SRC_PUT += ft_putstr_fd.c

SOURCES_PUT = $(addprefix $(SDIR_PUT)/,$(SRC_PUT))
OBJECTS_PUT = $(addprefix $(ODIR_PUT)/,$(SRC_PUT:.c=.o))

# /*
# ** ================= SOURCE STRING NEW ==========================
# */

SDIR_STRING = src/ft_string
ODIR_STRING = obj/ft_string

SRC_STRING = ft_str_ind.c
SRC_STRING += ft_strany.c
SRC_STRING += ft_strcat.c
SRC_STRING += ft_strchr.c
SRC_STRING += ft_strclr.c
SRC_STRING += ft_strcmp.c
SRC_STRING += ft_strcpy.c
SRC_STRING += ft_strdel.c
SRC_STRING += ft_strdup.c
SRC_STRING += ft_strequ.c
SRC_STRING += ft_striter.c
SRC_STRING += ft_striteri.c
SRC_STRING += ft_strjoin.c
SRC_STRING += ft_strlcat.c
SRC_STRING += ft_strlen.c
SRC_STRING += ft_strmap.c
SRC_STRING += ft_strmapi.c
SRC_STRING += ft_strncat.c
SRC_STRING += ft_strncmp.c
SRC_STRING += ft_strncpy.c
SRC_STRING += ft_strnequ.c
SRC_STRING += ft_strnew.c
SRC_STRING += ft_strnstr.c
SRC_STRING += ft_strrchr.c
SRC_STRING += ft_strrev.c
SRC_STRING += ft_strsplit.c
SRC_STRING += ft_strsplitfree.c
SRC_STRING += ft_strstr.c
SRC_STRING += ft_strsub.c
SRC_STRING += ft_strtrim.c
SRC_STRING += ft_strmerge.c

SOURCES_STRING = $(addprefix $(SDIR_STRING)/,$(SRC_STRING))
OBJECTS_STRING = $(addprefix $(ODIR_STRING)/,$(SRC_STRING:.c=.o))


# /*
# ** ====================== SOURCE ARRAY ==========================
# */

SDIR_ARRAY = src/ft_array
ODIR_ARRAY = obj/ft_array

SRC_ARRAY = ft_array_min.c
SRC_ARRAY += ft_array_max.c
SRC_ARRAY += ft_array_print.c
SRC_ARRAY += ft_free_matrix.c
SRC_ARRAY += ft_create_matrix.c
SRC_ARRAY += ft_print_matrix.c
SRC_ARRAY += ft_copy_matrix.c

SOURCES_ARRAY = $(addprefix $(SDIR_ARRAY)/,$(SRC_ARRAY))
OBJECTS_ARRAY = $(addprefix $(ODIR_ARRAY)/,$(SRC_ARRAY:.c=.o))

# /*
# ** ====================== SOURCE GNL ============================
# */

SDIR_GNL = src/ft_gnl
ODIR_GNL = obj/ft_gnl

SRC_GNL = get_next_line.c

SOURCES_GNL = $(addprefix $(SDIR_GNL)/,$(SRC_GNL))
OBJECTS_GNL = $(addprefix $(ODIR_GNL)/,$(SRC_GNL:.c=.o))

# /*
# ** ====================== SOURCE QUEUE ============================
# */

SDIR_QUEUE = src/ft_queue
ODIR_QUEUE = obj/ft_queue

SRC_QUEUE = ft_qdel.c
SRC_QUEUE += ft_qpop.c
SRC_QUEUE += ft_qpush.c

SOURCES_QUEUE = $(addprefix $(SDIR_QUEUE)/,$(SRC_QUEUE))
OBJECTS_QUEUE = $(addprefix $(ODIR_QUEUE)/,$(SRC_QUEUE:.c=.o))



# /*
# ** ====================== SOURCE PRINTF ==========================
# */

SDIR_PRINTF = src/ft_printf
ODIR_PRINTF = obj/ft_printf

SRC_PRINTF = buffer_n_print.c
SRC_PRINTF += float_processing.c
SRC_PRINTF += float_processing_ag.c
SRC_PRINTF += float_processing_ef.c
SRC_PRINTF += float_processing_fast_dtoa.c
SRC_PRINTF += float_processing_fast_ldtoa.c
SRC_PRINTF += float_processing_fxd_dbl.c
SRC_PRINTF += ft_printf.c
SRC_PRINTF += ft_printf_utils.c
SRC_PRINTF += get_format_arg.c
SRC_PRINTF += number_processing.c
SRC_PRINTF += string_processing.c
SRC_PRINTF += ft_assert.c

SOURCES_PRINTF = $(addprefix $(SDIR_PRINTF)/,$(SRC_PRINTF))
OBJECTS_PRINTF = $(addprefix $(ODIR_PRINTF)/,$(SRC_PRINTF:.c=.o))

# /*
# ** ====================== SOURCE LST ==========================
# */

SDIR_LST = src/ft_lst
ODIR_LST = obj/ft_lst

SRC_LST = ft_lstadd.c
SRC_LST += ft_lstaddcontent.c
SRC_LST += ft_lstdel.c
SRC_LST += ft_lstdelone.c
SRC_LST += ft_lstiter.c
SRC_LST += ft_lstlink.c
SRC_LST += ft_lstmap.c
SRC_LST += ft_lstnew.c
SRC_LST += ft_lstpushback.c
SRC_LST += ft_lstprint.c
SRC_LST += ft_lstprint_fd.c


SOURCES_LST = $(addprefix $(SDIR_LST)/,$(SRC_LST))
OBJECTS_LST = $(addprefix $(ODIR_LST)/,$(SRC_LST:.c=.o))


HEADERS = $(addprefix $(HDIR)/,$(HEAD))

.PHONY: clean fclean all re

all : $(NAME) Makefile
	@2> tmp.log
	@@echo "Project $(NAME) build successfully \c" >> tmp.log

$(NAME) :	$(OBJECTS_MEMORY)  $(OBJECTS_PUT) $(OBJECTS_STRING) $(OBJECTS_GNL) $(OBJECTS_QUEUE) \
			$(OBJECTS_PRINTF) $(OBJECTS_ARRAY) $(OBJECTS_LST) $(HEADERS)  $(OBJECTS_OTHER) Makefile
	@ar rc  $(NAME) $? 2> tmp.log
	@ranlib $(NAME) 2> tmp.log
	@echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m\n"

# /*
# ** ====================== MAKE MEMORY ==========================
# */
$(ODIR_MEMORY)/%.o : $(SDIR_MEMORY)/%.c $(HEADERS) Makefile
	@if [[ $< == src/ft_memory/ft_memalloc.c ]]; then \
		echo "\nMake \033[33m$(NAME):\033[0m\c"; \
	fi
	@if [[ $< == src/ft_memory/ft_memalloc.c ]]; then \
		echo "\n > Make \033[33mmemory\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR) 2> tmp.log
	@mkdir -p $(ODIR_MEMORY) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


# /*
# ** ====================== MAKE PUT ==========================
# */
$(ODIR_PUT)/%.o : $(SDIR_PUT)/%.c $(HEADERS) Makefile
	@if [[ $< == src/ft_put/ft_putchar.c ]]; then \
		echo "\n > Make \033[33mput\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_PUT) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


# /*
# ** ====================== MAKE STRING ==========================
# */
$(ODIR_STRING)/%.o : $(SDIR_STRING)/%.c $(HEADERS) Makefile
	@if [[ $< == src/ft_string/ft_str_ind.c ]]; then \
		echo "\n > Make \033[33mstring\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_STRING) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


# /*
# ** ====================== MAKE GNL ==========================
# */
$(ODIR_GNL)/%.o : $(SDIR_GNL)/%.c $(HEADERS) Makefile
	@if [[ $< == src/ft_gnl/get_next_line.c ]]; then \
		echo "\n > Make \033[33mgnl\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_GNL) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** ====================== MAKE QUEUE ==========================
# */
$(ODIR_QUEUE)/%.o : $(SDIR_QUEUE)/%.c $(HEADERS) Makefile
	@if [[ $< == src/ft_queue/ft_qdel.c ]]; then \
		echo "\n > Make \033[33mqueue\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_QUEUE) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

# /*
# ** ====================== MAKE LST ==========================
# */
$(ODIR_LST)/%.o : $(SDIR_LST)/%.c $(HEADERS) Makefile
	@if [[ $< == src/ft_lst/ft_lstadd.c ]]; then \
		echo "\n > Make \033[33mlist\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_LST) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


# /*
# ** ====================== MAKE ARRAY ==========================
# */
$(ODIR_ARRAY)/%.o : $(SDIR_ARRAY)/%.c $(HEADERS) Makefile
	@if [[ $< == src/ft_array/ft_array_min.c ]]; then \
		echo "\n > Make \033[33marray\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_ARRAY) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


# /*
# ** ====================== MAKE PRINTF ==========================
# */
$(ODIR_PRINTF)/%.o : $(SDIR_PRINTF)/%.c $(HEADERS) Makefile
	@if [[ $< == src/ft_printf/buffer_n_print.c ]]; then \
		echo "\n > Make \033[33mprintf\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_PRINTF) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


# /*
# ** ====================== MAKE OTHER ==========================
# */
$(ODIR_OTHER)/%.o : $(SDIR_OTHER)/%.c $(HEADERS) Makefile
	@if [[ $< == src/ft_other/ft_atoill.c ]]; then \
		echo "\n > Make \033[33mother\033[0m\tfunctions:\c"; \
	fi
	@mkdir -p $(ODIR_OTHER) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


clean:
	@rm -rf $(ODIR) 2> tmp.log

fclean: clean
	@rm -f $(NAME) 2> tmp.log
	@echo "\033[31m> Clear $(NAME)\033[0m"

re: fclean all

# $(OBJECTS)  $(OBJECTS_PRINTF)  $(OBJECTS_ARRAY) $(OBJECTS_STRING) $(HEADERS)

# printOther $(OBJECTS) printPrintf $(OBJECTS_PRINTF) printArray $(OBJECTS_ARRAY) $(OBJECTS_STRING) $(HEADERS)
