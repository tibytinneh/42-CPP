# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aang-shu <aang-shu.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 18:05:37 by aang-shu          #+#    #+#              #
#    Updated: 2025/02/05 17:04:38 by aang-shu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#************************************************************************#
# COLOURS #
#************************************************************************#
GREEN = $(shell tput setaf 2)
RED = $(shell tput setaf 1)
YELLOW = $(shell tput setaf 3)
BLUE = $(shell tput setaf 4)
MAGENTA = $(shell tput setaf 5)
CYAN = $(shell tput setaf 6)
RESET = $(shell tput sgr0)
#************************************************************************#
# NAME, compiler, compiler flags, rm #
#************************************************************************#
NAME := ClapTrap
CC := c++
SYSTEM :=- $(shell uname -s)
ifneq (,$(findstring MINGW, $(SYSTEM)))
	CPPFLAGS = -Wall -Wextra -Werror -std=gnu++98
else
	CPPFLAGS = -Wall -Wextra -Werror -std=c++98
endif
RM := rm -rf
MKDIR := mkdir -p
#************************************************************************#
# Source - paths annd filenames #
#************************************************************************#
SRCS = main.cpp ClapTrap.cpp Utils.cpp
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.cpp=%.o))
DEPS = $(OBJS:.o=.d)
#************************************************************************#

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)Building $(NAME)$(RESET)"
	@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	@$(MKDIR) $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) $(CPPFLAGS) -MMD -c $< -o $@

$(OBJ_DIR):
	@echo "$(YELLOW)Creating $(OBJ_DIR) directory$(RESET)"
	@$(MKDIR) $(OBJ_DIR)
clean:
	@echo "$(RED)Cleaning object files and dependencies: $(RESET)"
	@echo "$(OBJS)"
	@echo "$(DEPS)"
	@echo "$(OBJ_DIR)"
	@$(RM) $(OBJS) $(DEPS) $(OBJ_DIR)
fclean: clean
	@echo "$(RED)Cleaning executable files: $(RESET)"
	@echo "$(NAME)"
	@$(RM) $(NAME)
re: fclean all

-include $(DEPS)
