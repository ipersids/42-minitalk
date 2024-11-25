# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 23:09:38 by ipersids          #+#    #+#              #
#    Updated: 2024/11/25 17:24:09 by ipersids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation variables
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR 			= ar
ARFLAGS 	= -rcs

# Platform-specific settings
ifeq ($(OS),Windows_NT)
    RM = del /q
    RM_DIR = rmdir /s /q
    LIB_EXT = .lib
else
    RM = rm -f
    RM_DIR = rm -rf
    LIB_EXT = .a
endif

# File names
NAME		:= libftprintf$(LIB_EXT)
SRCS		:= ft_printf.c ft_puthex_fd.c ft_putptr_fd.c ft_putunmb_fd.c \
			   ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_strchr.c \
			   ft_strlen.c ft_atoi.c
OBJ			:= $(SRCS:%.c=%.o)

# Targets
all: $(NAME)

# Create the libftprintf library
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@echo "\nLibrary $(NAME) created.\n"

# Compile object files
%.o: %.c 
	$(CC) $(CFLAGS) $(HDRS) -c $< -o $@
	@echo "Compiled $< into $@"

# Clean object files
clean:
	@$(RM) -f $(OBJ)
	@echo "Cleaned up $(NAME) object files."

# Remove all compiled files
fclean: clean
	@$(RM) -f $(NAME)
	@echo "Cleaned up $(NAME) executable files."

# Rebuild everything
re: fclean all
	@echo "Cleaned up $(NAME) objects + executable and rebuilded library."

.PHONY: all clean fclean re
