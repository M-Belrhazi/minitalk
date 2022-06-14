CFLAGS= -Wall -Werror -Wextra

SRCS= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
		ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c\
		ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c\
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
		ft_substr.c ft_tolower.c ft_toupper.c

BONUS= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_lstmap.c

BONUS_OBJS= $(BONUS:.c=.o)

OBJS= $(SRCS:.c=.o)

NAME= libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

bonus : $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

re : fclean all

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

.PHONY : all clean fclean re bonus

#r = add new files
#c = create if it did not exist
#s = update the index
