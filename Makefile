NAME = push_swap

SRCS = ./operations.c \
		./operations1.c \
		./operations2.c \
		./push_swap.c \
		./utils.c \
		./sort.c \
		./basic_sort.c \
		./checkers.c \
	 
OBJS = $(SRCS:.c=.o)

HEADER	= push_swap.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I include

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c	$(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJS)

fclean: clean
		@$(RM) $(NAME) 

re: fclean all

.PHONY : all clean fclean re