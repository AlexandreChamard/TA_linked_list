CC	=	gcc

AR	=	ar rc

CFLAGS	=	-W -Wall -Wextra -Werror
CFLAGS	+=	-I../include

SRC	=	list.c

OBJ	=	$(SRC:.c=.o)

NAME	=	liblist.a

all	:	$(NAME)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

$(NAME)	:	$(OBJ)
		$(AR) $(NAME) $(OBJ)
