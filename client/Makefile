INC_PATH = ./includes/

LIB_PATH = ../libft/
LIB_NAME = libft.a
LIB_TOTAL = $(addprefix $(LIB_PATH),$(LIB_NAME))

SRC_PATH = ./src/
SRC_NAME =	main.c\
			get_next_line.c\
			more_func.c\
			file_transfer.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))

all: success

success: $(NAME)
	@echo "\nProject compilated."

$(NAME): $(LIB_TOTAL) $(OBJ)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(LIB_TOTAL) $(OBJ)

$(LIB_TOTAL):
	@cd $(LIB_PATH) ; $(MAKE) -f Makefile

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@/bin/echo -n "."

clean:
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@cd $(LIB_PATH) ; $(MAKE) -f Makefile clean

fclean: clean
	@rm -fv $(NAME)
	@cd $(LIB_PATH) ; $(MAKE) -f Makefile fclean

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
