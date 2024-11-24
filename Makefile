# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 21:45:59 by ipersids          #+#    #+#              #
#    Updated: 2024/11/23 22:31:18 by ipersids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Programme variables
SERVER			:= server
CLIENT			:= client

# Compilation variables
CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror

# File names
SRC_CLIENT		:= client.c
SRC_SERVER		:= server.c
OBJ_CLIENT		:= $(SRC_CLIENT:.c=.o)
OBJ_SERVER		:= $(SRC_SERVER:.c=.o)

# Submodule-specific variables
SUBMODULE_DIR	:= ft-printf
SUBMODULE_LIB	:= $(SUBMODULE_DIR)/libftprintf.a

# Default target
all: submodules $(SUBMODULE_LIB) $(SERVER) $(CLIENT)

# Build the server executable
$(SERVER): $(OBJ_SERVER) $(SUBMODULE_LIB)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(SUBMODULE_LIB) -o $(SERVER)

# Build the client executable
$(CLIENT): $(OBJ_CLIENT) $(SUBMODULE_LIB)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(SUBMODULE_LIB) -o $(CLIENT)

# Rule to compile source files
%.o: %.c
	@$(CC) $(CFLAGS) -I$(SUBMODULE_DIR) -c $< -o $@

# Build the submodule library
$(SUBMODULE_LIB):
	$(MAKE) -C $(SUBMODULE_DIR)

# Initialize and update submodules
submodules:
	@git submodule update --init --recursive

# Clean the main project
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) -C $(SUBMODULE_DIR) clean

# Clean everything including the executable
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C $(SUBMODULE_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all submodules clean fclean re
