# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 10:18:33 by hgamiz-g          #+#    #+#              #
#    Updated: 2025/08/31 16:20:05 by hgamiz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCES = ft_atoi.c ft_memchr.c ft_split.c ft_strmapi.c\
	ft_bzero.c ft_memcmp.c ft_strchr.c ft_strncmp.c\
	ft_calloc.c ft_memcpy.c ft_strnstr.c\
	ft_isalnum.c ft_memmove.c ft_strdup.c ft_strrchr.c\
	ft_isalpha.c ft_memset.c ft_striteri.c ft_strtrim.c\
	ft_isascii.c ft_putchar_fd.c ft_strjoin.c ft_substr.c\
	ft_isdigit.c ft_putendl_fd.c ft_strlcat.c ft_tolower.c\
	ft_isprint.c ft_putnbr_fd.c ft_strlcpy.c ft_toupper.c\
	ft_itoa.c ft_putstr_fd.c ft_strlen.c ft_pr_hex.c\
	ft_pr_unsigned.c ft_putnbr.c ft_putstr.c ft_printf.c\
	ft_putchar.c ft_putptr.c ft_itobin.c ft_bintoi.c get_next_line.c \
	get_next_line_utils.c ft_strcalloc.c ft_lstadd_front.c ft_lstadd_back.c \
	ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_isspace.c ft_strcmp.c ft_perror.c
	   
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Werror -Wextra -Wall

# Colors for pretty output
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "📦 $(BLUE)Creating archive libft.a...$(RESET)"
	@$(AR) -r $@ $? 2>/dev/null
	@echo "✅ $(GREEN)libft.a created successfully!$(RESET)"

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

clean: 
	@echo "🧹 $(YELLOW)Cleaning libft object files...$(RESET)"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "🗑️  $(RED)Removing libft.a...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
