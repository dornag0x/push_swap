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
CC = gcc
CFLAGS = -Wall -Wextra -Werror

EXEC = push_swap
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ./printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
OBJDIR = build

SRC = $(wildcard ./src/main/*.c) \
      $(wildcard ./src/misc/*.c) \
      $(wildcard ./src/error/*.c) \
      $(wildcard ./src/print/*.c) \
      $(wildcard ./src/action/*.c) \
      $(wildcard ./src/lister/*.c) \
      $(wildcard ./src/parsing/*.c) \
      $(wildcard ./src/algo/*.c)

OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

LIB = -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf

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
	@$(CC) $(CFLAGS) -g -c $< -o $@

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
	@rm -f -r $(OBJ)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(FT_PRINTF_DIR) clean

fclean: clean
	@echo "$(RED)[Full cleanup] Removing executable...$(RESET)"
	@rm -f -r $(EXEC) $(OBJDIR)
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

