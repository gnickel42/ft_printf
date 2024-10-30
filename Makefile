NAME	= libftprintf.a

OBJ_DIR = obj
SRC_DIR = src/
HEADER	= include/ft_printf.h

SRC		= src/ft_printf.c src/ft_print_char.c src/ft_print_str.c\
		  src/ft_print_int.c src/ft_print_unsigned.c src/ft_print_hex.c\
		  src/ft_print_ptr.c

CFLAGS	= -Wall -Werror -Wextra -I include
CC		= cc
OBJ		= $(SRC:.c=.o)
OBJ		:= $(patsubst $(SRC_DIR)/%.o, $(OBJ_DIR)/%.o, $(OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
