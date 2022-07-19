SRCS				= draw_with_minilibx.c

OBJS				= $(SRCS:.c=.o)

RM 					= rm -f

CC					= clang	

#CFLAGS 				= -Wall -Wextra -Werror
MINILIBX_FLAGS		= -lX11 -lXext -lmlx

NAME				= so_long

all:				$(NAME)

run:				
					./so_long				

$(NAME):			$(OBJS)
					$(CC) $(SRCS) $(CFLAGS) $(MINILIBX_FLAGS) -o $(NAME)


clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:			all clean fclean re