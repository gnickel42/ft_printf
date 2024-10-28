NAME	= ft_printf.a

OBJ_DIR = obj/
SRC_DIR = src/
HEADER	= include/ft_printf.h

SRC		= $(SRC_DIR)ft_printf.c

CFLAGS	= -Wall -Werror -Wextra
CC		= cc
OBJ		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I include -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
