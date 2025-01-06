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
LIB = lib/libft/libft.a

OBJDIR = obj

SRC = $(wildcard ./src/main/*.c) \
	  $(wildcard ./src/misc/*.c) \
	  $(wildcard ./src/error/*.c) \
	  $(wildcard ./src/print/*.c) \
	  $(wildcard ./src/action/*.c) \
	  $(wildcard ./src/lister/*.c) \
	  $(wildcard ./src/parsing/*.c) \


OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

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

all: header $(EXEC)

header:
	clear
	@echo  "$$HEADER"

$(OBJDIR)/%.o: %.c
#	@echo "$(GREEN)[COMPILING SOURCE] $< INTO OBJECT $@ $(RESET)"
	@mkdir -p '$(@D)'
	@$(CC) -c $(CFLAGS) -g -c $< -o $@

$(EXEC): $(OBJ)
	@echo "$(GREEN)[Linking] Creating executable $(EXEC)...$(RESET)"
	@$(CC) $(OBJ) $(LIB) -o $(EXEC)
	@echo "$(GREEN)[Executable generated] You can run it with './$(EXEC)'$(RESET)"

test: CFLAGS =
test: clean header $(EXEC)
	@echo "$(GREEN)[Test Compilation] Executable $(EXEC) ready to use without warning flags$(RESET)"

clean:
	@echo "$(RED)[Cleaning] Removing object files...$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)[Full cleanup] Removing executable...$(RESET)"
	@rm -f $(EXEC)

re: fclean all
	@echo "$(GREEN)[Rebuilding] Everything is recompiled!$(RESET)"

info:
	@echo "$(GREEN)[Info]	       Executable is named $(EXEC)"
	@echo "$(GREEN)[Source files] $(SRC)"
	@echo "$(GREEN)[Object files] $(OBJ)"
	@echo "$(GREEN)[Libraries]    $(LIB)"
	@echo "$(GREEN)[Executable]   ./$(EXEC)$(RESET)"

.PHONY: all clean fclean re info header fast

