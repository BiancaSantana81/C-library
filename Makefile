# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 18:22:28 by bsantana          #+#    #+#              #
#    Updated: 2024/05/18 18:22:30 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN :=	\033[1;32m
WHITE :=	\033[1;37m
PURPLE :=	\033[1;35m

NAME = libft.a
MAKEFLAGS += --silent

SRC_DIR = sources
OBJ_DIR = objects

HEADERS := -I includes

FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c  ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c  ft_strrncmp.c ft_strdup.c ft_atoi.c \
		ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_fd.c ft_substr.c \
		ft_itoa.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_split.c  ft_free_matrix.c ft_atol.c \
		ft_strstr.c get_next_line.c

SRCS = $(addprefix $(SRC_DIR)/,$(FILES))
OBJS = $(addprefix $(OBJ_DIR)/,$(FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(HEADERS) -c $< -o $@ $(FLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(PURPLE)  🌺 $(NAME) ready to use! 🌺 "

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo "$(WHITE) 🫧🫧  Cleaning  $(NAME) completed! 🫧🫧"

re: fclean all

.PHONY: all clean fclean re
