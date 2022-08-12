SRCS_FILES			= image_utils.c map_utils.c map.c renders.c so_long.c \
							events.c events_utils.c game.c

SRCS_FILES_BONUS	= image_utils_bonus.c map_utils_bonus.c map_bonus.c renders_bonus.c \
						so_long_bonus.c events_bonus.c events_utils_bonus.c game_bonus.c \
						animation_bonus.c animation_utils_bonus.c move_enemies.c

SRCS_DIR			= sources

SRCS_DIR_BONUS		= sources_bonus

SRCS				= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

SRCS_BONUS			= $(addprefix $(SRCS_DIR_BONUS)/, $(SRCS_FILES_BONUS))

OBJS				= $(SRCS:.c=.o)

OBJS_BONUS			= $(SRCS_BONUS:.c=.o)

LIBFT_DIR			= ./libs/libft
MINILIBX_DIR		= ./libs/minilibx

LIBFT				= ./libs/libft/libft.a
MINILIBX			= ./libs/minilibx/libmlx.a

RM 					= rm -f

CC					= clang	

CFLAGS 				= -Wall -Wextra -Werror
MINILIBX_FLAGS		= -L. -lXext -L. -lX11

NAME				= so_long
NAME_BONUS			= so_long_bonus

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME):			$(LIBFT) $(MINILIBX) $(OBJS)
					$(CC) -g3 $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MINILIBX_FLAGS) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(MINILIBX) $(OBJS_BONUS)
					$(CC) -g3 $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MINILIBX) $(MINILIBX_FLAGS) -o $(NAME_BONUS)

$(LIBFT):			
					$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):		
					$(MAKE) -C $(MINILIBX_DIR)
					
clean:
					$(MAKE) clean -C $(LIBFT_DIR)
					$(MAKE) clean -C $(MINILIBX_DIR)
					$(RM) $(OBJS)
					$(RM) $(OBJS_BONUS)

fclean:				clean
					$(MAKE) fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)
					$(RM) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re libft minilibx