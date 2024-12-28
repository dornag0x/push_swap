# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 11:12:55 by hfeufeu           #+#    #+#              #
#    Updated: 2024/12/28 11:13:03 by hfeufeu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap.a
LIBNAME = libft.a \
		  libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBDIR = ./lib/libft \
		./lib/ft_printf

SRCS = main.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all
