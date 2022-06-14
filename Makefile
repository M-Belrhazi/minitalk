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

bonus : server_bonus client_bonus

server_bonus : server_bonus.o $(LIB)
	$(CC) $(CFLAGS) server_bonus.o $(LIB) -o server_bonus

client_bonus : client_bonus.o $(LIB)
	$(CC) $(CFLAGS) client_bonus.o $(LIB) -o client_bonus

clean :
	rm -f client.o server.o client_bonus.o server_bonus.o
	make clean -C libftprintf

fclean : clean
	rm -f $(NAME) client server_bonus client_bonus
	make fclean -C libftprintf

.PHONY : all clean fclean re
