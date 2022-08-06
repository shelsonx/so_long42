SRCS				= image_utils.c map_utils.c map.c renders.c so_long.c events.c events_utils.c game.c

OBJS				= $(SRCS:.c=.o)

RM 					= rm -f

CC					= clang	

CFLAGS 				= -Wall -Wextra -Werror
MINILIBX_FLAGS		= -lX11 -lXext -lmlx

NAME				= so_long

all:				$(NAME)

run:				
					valgrind --leak-check=full --show-leak-kinds=all \
					--track-origins=yes ./so_long maps/my_map.ber

$(NAME):			$(OBJS)
					$(CC) -g3 $(SRCS) libs/libft/libft.a $(CFLAGS) $(MINILIBX_FLAGS) -o $(NAME)


clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:			all clean fclean re