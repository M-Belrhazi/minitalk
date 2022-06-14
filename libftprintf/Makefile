CFLAGS= -Wall -Werror -Wextra

SRCS= ft_printf.c ft_forest.c ft_print_address.c ft_print_char.c\
		ft_print_hex.c ft_print_nbr.c ft_print_str.c ft_print_unsigned.c\
		ft_putnbr_hex_fd.c ft_putnbr_printf_fd.c ft_putstr_printf_fd.c\
		ft_write_nbr.c

OBJS= $(SRCS:.c=.o)

LIBFT= libft.a

NAME= libftprintf.a

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./libft
	cp ./libft/$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

re : fclean all

clean :
	rm -f $(OBJS)
	make clean -C ./libft

fclean : clean
	rm -f $(NAME)
	rm -f ./libft/$(LIBFT)

.PHONY : all clean fclean re

#r = add new files
#c = create if it did not exist
#s = update the index
