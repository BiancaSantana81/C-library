NAME = libft.a
MAKEFLAGS += --silent

FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c  ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c  ft_strrncmp.c ft_strdup.c ft_atoi.c \
ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_fd.c ft_substr.c \
ft_itoa.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_split.c  ft_free_matrix.c ft_atol.c \
ft_strstr.c get_next_line.c

FILES_O = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_O)
	ar rcs $(NAME) $(FILES_O)

%.o: %.c
	cc -c $< -o $@ -Wall -Wextra -Werror

clean: 
	rm -f $(FILES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
