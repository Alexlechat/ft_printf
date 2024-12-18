
.PHONY: all clean fclean re bonus


##########################################
############		FILES		##########
##########################################

SRC = ft_printf.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putptr.c


##########################################
##########		VARIABLES		##########
##########################################

CC = cc
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)
HEADER = ft_printf.h
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@


##########################################
############		RULES		##########
##########################################

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: 
	rm -f $(NAME)
	$(MAKE) clean

re:
	$(MAKE) fclean
	$(MAKE) all