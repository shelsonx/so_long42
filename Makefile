SRCS_FILES			= image_utils.c map_utils.c map.c renders.c so_long.c \
							events.c events_utils.c game.c
SRCS_DIR			= sources

SRCS				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))	

OBJS				= $(SRCS:.c=.o)

LIBFT_DIR			= ./libs/libft
MINILIBX_DIR		= ./libs/minilibx

LIBFT				= ./libs/libft/libft.a
MINILIBX			= ./libs/minilibx/libmlx.a

RM 					= rm -f

CC					= clang	

CFLAGS 				= -Wall -Wextra -Werror
MINILIBX_FLAGS		= -L. -lXext -L. -lX11

NAME				= so_long

all:				$(NAME)

$(NAME):			$(LIBFT) $(MINILIBX) $(OBJS)
					$(CC) -g3 $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MINILIBX_FLAGS) -o $(NAME)

$(LIBFT):			$(LIBFT_DIR)
					$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):		$(MINILIBX_DIR)
					$(MAKE) -C $(MINILIBX_DIR)
					
clean:
					$(MAKE) clean -C $(LIBFT_DIR)
					$(MAKE) clean -C $(MINILIBX_DIR)
					$(RM) $(OBJS)

fclean:				clean
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft minilibx