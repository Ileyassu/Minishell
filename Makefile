SRC = main.c \
	  minishell.c \
	  errors.c \
	  ft_reset.c \
	  tools.c \
	  lexer/lexer_tools.c \
	  lexer/make_tokens.c \
	  parsing/command.c \
	  parsing/init_command.c \
	  parsing/parse.c \
	  parsing/parsing_init.c \
	  parsing/parsing_tools.c

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