NAME	= libftprintf.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f
AR	= ar rcs

SRCS	= ft_printf.c ft_fonc.c ft_putnbr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re 
