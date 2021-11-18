# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 20:29:15 by kangkim           #+#    #+#              #
#    Updated: 2021/11/18 16:38:51 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_isalpha	\
	ft_isdigit		\
	ft_isalnum		\
	ft_isascii		\
	ft_isprint		\
	ft_strlen		\
	ft_memset		\
	ft_bzero		\
	ft_memcpy		\
	ft_memmove		\
	ft_strlcpy		\
	ft_strlcat		\
	ft_toupper		\
	ft_tolower		\
	ft_strchr		\
	ft_strrchr		\
	ft_strncmp		\
	ft_memchr		\
	ft_memcmp		\
	ft_strnstr		\
	ft_atoi			\
	ft_calloc		\
	ft_strdup		\
	ft_substr		\
	ft_strjoin		\
	ft_strtrim		\
	ft_split		\
	ft_itoa			\
	ft_strmapi		\
	ft_striteri		\
	ft_putchar_fd	\
	ft_putstr_fd	\
	ft_putendl_fd	\
	ft_putnbr_fd	\

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
