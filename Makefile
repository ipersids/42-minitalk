# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 21:45:59 by ipersids          #+#    #+#              #
#    Updated: 2024/11/28 12:11:41 by ipersids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Programme variables
SERVER			:= ./server
CLIENT			:= ./client

# Compilation variables
CC				:= clang
CFLAGS			:= -Wall -Wextra -Werror #-g
HDRS			:= -Iinclude -Ift-printf

# Dir. names
DIR_UTILS		:= src/minitalk-utils
DIR_SRCS		:= src

# File names
SRC_CLIENT		:= $(DIR_SRCS)/client.c
SRC_SERVER		:= $(DIR_SRCS)/server.c
SRC_UTILS		:= $(DIR_UTILS)/sigaction_init.c $(DIR_UTILS)/kill_safe.c \
				   $(DIR_UTILS)/ft_realloc.c

OBJ_CLIENT		:= $(SRC_CLIENT:.c=.o)
OBJ_SERVER		:= $(SRC_SERVER:.c=.o)
OBJ_UTILS		:= $(SRC_UTILS:.c=.o)

# ft_printf library
LIB_DIR	:= ft-printf
LIB	:= $(LIB_DIR)/libftprintf.a

# Default target
all: $(LIB) $(SERVER) $(CLIENT)

# Build the server executable
$(SERVER): $(OBJ_SERVER) $(OBJ_UTILS) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_UTILS) $(LIB) -o $(SERVER)

# Build the client executable
$(CLIENT): $(OBJ_CLIENT) $(OBJ_UTILS) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_UTILS) $(LIB) -o $(CLIENT)

# Rule to compile source files
%.o: %.c
	@$(CC) $(CFLAGS) $(HDRS) -c $< -o $@

# Build the submodule library
$(LIB):
	$(MAKE) -C $(LIB_DIR)

# Clean the main project
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_UTILS)
	$(MAKE) -C $(LIB_DIR) clean

# Clean everything including the executable
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIB_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
