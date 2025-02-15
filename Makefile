# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfeufeu <hfeufeu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 11:12:55 by hfeufeu           #+#    #+#              #
#    Updated: 2025/02/15 11:29:43 by hfeufeu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

EXEC = push_swap
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ./printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
OBJDIR = .build
SRCDIR = src

SRC = main/push_swap_main.c \
	  main/check_arg.c \
	  action/push.c \
	  action/reverse_rotate.c \
	  action/rotate.c \
	  action/swap.c \
	  algo/big_algo.c \
	  algo/controller.c \
	  algo/short_algo.c \
	  algo/normalizer.c \
	  lister/ps_lstadd_back.c \
	  lister/ps_lstadd_front.c \
	  lister/ps_lstclear.c \
	  lister/ps_lstclear_last.c \
	  lister/ps_lstcpy.c \
	  lister/ps_lstdelone.c \
	  lister/ps_lstiter.c \
	  lister/ps_lstlast.c \
	  lister/ps_lstnew.c \
	  lister/ps_lstsize.c \
	  misc/cpy_lst.c \
	  misc/err_handle.c \
	  misc/init.c \
	  misc/push_swap_utils.c \

SRC := $(addprefix $(SRCDIR)/, $(SRC))

OBJ := $(addprefix $(OBJDIR)/, $(SRC:%.c=%.o))

IFLAGS = -I ./include

LIB = -L$(LIBFT_DIR) -g -lft -L$(FT_PRINTF_DIR) -lftprintf

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

define HEADER
$(GREEN)██████╗ ██╗   ██╗███████╗██╗  ██╗███████╗██╗    ██╗ █████╗ ██████╗ $(RESET) 
$(GREEN)██╔══██╗██║   ██║██╔════╝██║  ██║██╔════╝██║    ██║██╔══██╗██╔══██╗$(RESET) 
$(GREEN)██████╔╝██║   ██║███████╗███████║███████╗██║ █╗ ██║███████║██████╔╝$(RESET) 
$(GREEN)██╔═══╝ ██║   ██║╚════██║██╔══██║╚════██║██║███╗██║██╔══██║██╔═══╝ $(RESET)
$(GREEN)██║     ╚██████╔╝███████║██║  ██║███████║╚███╔███╔╝██║  ██║██║     $(RESET)
$(GREEN)╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     $(RESET)
$(RED)By Dornagol$(RESET)
endef
export HEADER

all: header $(LIBFT) $(FT_PRINTF) $(EXEC)

header:
	clear
	@echo  "$$HEADER"

$(OBJDIR)/%.o: %.c
	@mkdir -p '$(@D)'
	@$(CC) $(CFLAGS) $(IFLAGS) -g -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -s -C $(FT_PRINTF_DIR)

$(EXEC): $(OBJ)
	@echo "$(GREEN)[Linking] Creating executable $(EXEC)...$(RESET)"
	@$(CC) $(OBJ) $(LIB) -o $(EXEC)
	@echo "$(GREEN)[Executable generated] You can run it with './$(EXEC)'$(RESET)"

test: CFLAGS =
test: clean header $(LIBFT) $(FT_PRINTF) $(EXEC)
	@echo "$(GREEN)[Test Compilation] Executable $(EXEC) ready to use without warning flags$(RESET)"

clean:
	@echo "$(RED)[Cleaning] Removing object files...$(RESET)"
	@rm -f -r $(OBJ) $(OBJDIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(FT_PRINTF_DIR) clean

fclean: clean
	@echo "$(RED)[Full cleanup] Removing executable...$(RESET)"
	@rm -f -r $(EXEC)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(FT_PRINTF_DIR) fclean

re: fclean all
	@echo "$(GREEN)[Rebuilding] Everything is recompiled!$(RESET)"

info:
	@echo "$(GREEN)[Info]\t       Executable is named $(EXEC)"
	@echo "$(GREEN)[Source files] $(SRC)"
	@echo "$(GREEN)[Object files] $(OBJ)"
	@echo "$(GREEN)[Libraries]    $(LIB)"
	@echo "$(GREEN)[Executable]   ./$(EXEC)$(RESET)"

.PHONY: all clean fclean re info header test

