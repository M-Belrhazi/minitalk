CC= cc

CFLAGS= -Wall -Werror -Wextra

LIB= libftprintf/libftprintf.a

NAME= server

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME) client

$(NAME) : server.o $(LIB)
	$(CC) $(CFLAGS) server.o $(LIB) -o $(NAME)

$(LIB) :
	make -C libftprintf

client: client.o $(LIB)
	$(CC) $(CFLAGS) client.o $(LIB) -o client

re : fclean all

clean :
	rm -f client.o server.o
	make clean -C libftprintf

fclean : clean
	rm -f $(NAME) client
	make fclean -C libftprintf

.PHONY : all clean fclean re
