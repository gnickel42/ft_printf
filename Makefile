NAME	= libftprintf.a

OBJ_DIR = obj
HEADER	= ft_printf.h

SRC		= ft_printf.c ft_print_char.c ft_print_str.c\
		  ft_print_int.c ft_print_unsigned.c ft_print_hex.c\
		  ft_print_ptr.c

CFLAGS	= -Wall -Werror -Wextra
CC		= cc
OBJ		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

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
