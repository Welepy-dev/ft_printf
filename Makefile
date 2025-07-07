# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 14:57:15 by marcsilv          #+#    #+#              #
#    Updated: 2025/05/06 14:36:20 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror -MMD -MP
RM = rm -rf
LIB = ar rcs

SRC = ./src/parsing.c                                                                 \
      ./src/ft_printf.c                                                               \
      ./src/utils/util.c                                                              \
      ./src/utils/string.c                                                            \
      ./src/utils/counters.c                                                          \
      ./src/utils/converters.c                                                        \
      ./src/printers/prints1.c                                                        \
      ./src/printers/prints2.c                                                        \
      ./src/flags_and_specifiers/print_hex.c                                          \
      ./src/flags_and_specifiers/print_ptr.c                                          \
      ./src/flags_and_specifiers/print_str.c                                          \
      ./src/flags_and_specifiers/print_char.c                                         \
      ./src/flags_and_specifiers/print_integer.c                                      \
      ./src/flags_and_specifiers/print_unsigned.c                                     \
      ./src/flags_and_specifiers/flags_and_specifiers.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

all: $(OBJ_DIR) $(NAME)

bonus: all

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ) $(DEP)

fclean: clean
	@$(RM) $(NAME) $(OBJ_DIR)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus

-include $(DEP)

