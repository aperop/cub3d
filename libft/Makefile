# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 17:59:45 by dhawkgir          #+#    #+#              #
#    Updated: 2022/01/09 14:59:45 by dhawkgir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

PATH_SRCS = sources/
PATH_INCLS = includes/

SRCS =	$(addprefix $(PATH_SRCS),				\
		ft_atoi.c			ft_bzero.c			\
		ft_calloc.c			ft_isalnum.c		\
		ft_isalpha.c		ft_isascii.c		\
		ft_isdigit.c		ft_isprint.c		\
		ft_itoa.c			ft_memchr.c			\
		ft_memcmp.c			ft_memcpy.c			\
		ft_memmove.c		ft_memset.c			\
		ft_putchar_fd.c		ft_putendl_fd.c		\
		ft_putnbr_fd.c		ft_putstr_fd.c		\
		ft_split.c			ft_strchr.c			\
		ft_strdup.c			ft_striteri.c		\
		ft_strjoin.c		ft_strlcat.c		\
		ft_strlcpy.c		ft_strlen.c			\
		ft_strmapi.c		ft_strncmp.c		\
		ft_strnstr.c		ft_strrchr.c		\
		ft_strtrim.c		ft_substr.c			\
		ft_tolower.c		ft_toupper.c		\
		ft_lstadd_back.c	ft_lstadd_front.c	\
		ft_lstclear.c		ft_lstdelone.c		\
		ft_lstiter.c		ft_lstlast.c		\
		ft_lstmap.c			ft_lstnew.c			\
		ft_lstsize.c		get_next_line.c		\
		get_next_line_utils.c)

OBJ = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $?
		@echo "\033[1m\033[32mLibft successfully created\033[39m"

%.o: %.c ${PATH_INCLS}/*.h
		@$(CC) $(FLAGS) -I ${PATH_INCLS} -c $< -o $@

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

norm:
	norminette $(PATH_SRCS) ${PATH_INCLS}

.PHONY: all clean fclean re norm
