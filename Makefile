SRC = main.c \
	  init_tools.c \
	  minishell.c \
	  check_tokens.c

RM = rm

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = minishell

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(OBJ) -lreadline libft.a -o $(NAME)

fclean : clean
		@echo full cleaning of $(NAME) ...
		@$(RM) -f $(NAME)
		@sleep 0.5
		@echo $(NAME) cleaned.

clean :
		@echo cleaning $(NAME) ...
		@$(RM) -f $(OBJ)
		@sleep 0.5
		@echo $(NAME) cleaned.

re : fclean all