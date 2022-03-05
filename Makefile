CC = cc -g
NAME = push_swap

SRCS = ft_atoi.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
ft_lstnew_bonus.c push_swap.c ft_split.c ft_lstsize_bonus.c

OBJS = ${SRCS:.c=.o}


.c.o:
		$(CC) $(CFLAGS) -c -o $@ $<

RM = rm -f

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(LFLAGS) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
