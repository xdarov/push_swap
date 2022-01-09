NAME =			push_swap

NAME_B =		checker		

SRCS =			push_swap_main.c push_swap.c push_swap_logic.c		\
				push_swap_move.c push_swap_mini.c ft_split.c		\
				push_swap_logic2.c push_swap_chek_and_free.c		\
				push_swap_logic3.c push_swap_utils.c

SRCS_B =		push_swap.c push_swap_utils.c push_swap_logic.c		\
				push_swap_move.c push_swap_mini.c ft_split.c		\
				push_swap_logic2.c push_swap_chek_and_free.c		\
				push_swap_logic3.c checker_utils.c checker.c

HEADER =		push_swap.h

OBJ =			$(patsubst %.c, %.o, $(SRCS))

OBJ_B =			$(patsubst %.c, %.o, $(SRCS_B))

CC =			gcc

CFLAGS =		-Wall -Wextra -Werror -I$(HEADER)

.PHONY:			all bonus clean fclean re

all:			$(NAME)

bonus:			$(NAME_B)

$(NAME):		$(HEADER) $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			
$(NAME_B):		$(HEADER) $(OBJ_B)
				$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)

clean:
				@rm -f $(OBJ) $(OBJ_B)

fclean:			clean
				@rm -f $(NAME) $(NAME_B)

re:				fclean all
