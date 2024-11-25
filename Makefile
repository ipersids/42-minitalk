# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 21:45:59 by ipersids          #+#    #+#              #
#    Updated: 2024/11/25 17:22:55 by ipersids         ###   ########.fr        #
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
LIB_DIR	:= ft-printf
LIB	:= $(LIB_DIR)/libftprintf.a

# Default target
all: $(LIB) $(SERVER) $(CLIENT)

# Build the server executable
$(SERVER): $(OBJ_SERVER) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIB) -o $(SERVER)

# Build the client executable
$(CLIENT): $(OBJ_CLIENT) $(LIB)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIB) -o $(CLIENT)

# Rule to compile source files
%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

# Build the submodule library
$(LIB):
	$(MAKE) -C $(LIB_DIR)

# Clean the main project
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) -C $(LIB_DIR) clean

# Clean everything including the executable
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIB_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
