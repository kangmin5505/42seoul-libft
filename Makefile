# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 20:29:15 by kangkim           #+#    #+#              #
#    Updated: 2021/12/27 22:12:45 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
_END	=	\033[0;0m
_GREEN	=	\033[0;32m

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
	ft_putchar		\
	ft_putstr		\
	ft_lltoa		\
	ft_uitoa		\
	ft_uitoa_base	\

FILES_B = ft_lstnew	\
	ft_lstadd_front	\
	ft_lstsize		\
	ft_lstlast		\
	ft_lstadd_back	\
	ft_lstdelone	\
	ft_lstclear		\
	ft_lstiter		\
	ft_lstmap		\

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_B)
else
	OBJ_FILES = $(OBJS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(_GREEN)[ Try to make $(NAME) ]$(_END)"
	@$(AR) $@ $^
	@echo "$(_GREEN)[ Done ]$(_END)"

bonus : 
	@echo "$(_GREEN)[ Try to make bonus ]$(_END)"
	@make WITH_BONUS=1 all
	@echo "$(_GREEN)[ Done ]$(_END)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(_GREEN)[ Try to clean]$(_END)"
	@$(RM) $(OBJS) $(OBJS_B)
	@echo "$(_GREEN)[ Done ]$(_END)"

fclean: clean
	@echo "$(_GREEN)[ Try to fclean]$(_END)"
	@$(RM) $(NAME)
	@echo "$(_GREEN)[ Done ]$(_END)"

re: fclean all

.PHONY: all bonus clean fclean re
