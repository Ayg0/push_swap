CC = cc -g
NAME = push_swap

CFLAGS = -Wall -Werror -Wextra

CHECKER = checker

SRCS = ft_atoi.c push_swap.c ft_split.c sort_three_fo_five.c \
		ft_printf/ft_printf.c ft_printf/printf_utils.c \
		the_makers.c sort_big_numbers.c utils1.c \
		less_instructions.c moves_functions.c utils2.c

C_SRCS = the_makers.c moves_functions.c utils1.c ft_atoi.c ft_split.c\
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
		sort_three_fo_five.c less_instructions.c sort_big_numbers.c\
		ft_printf/ft_printf.c ft_printf/printf_utils.c utils2.c checker_bonus.c
OBJS = ${SRCS:.c=.o}

C_OBJS = ${C_SRCS:.c=.o}

.c.o:
		$(CC) $(CFLAGS) -c -o $@ $<

RM = rm -f

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

$(CHECKER):	$(C_OBJS)
		$(CC) $(C_OBJS) -o $(CHECKER)

clean:
		$(RM) $(OBJS) $(C_OBJS)

fclean: clean
		$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
