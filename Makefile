LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	algo_a.c algo_b.c algo_utils.c error.c main.c parser.c
SOURCES_FILES	+=	push_swap.c utils.c utils_data.c utils_mem.c
SOURCES_FILES	+=	op_push.c op_rotate.c op_rrotate.c op_swap.c operator.c
SOURCES_FILES	+=	op_utils.c array_utils.c algo_utils2.c

SOURCES_BONUS	=	bonus_checker.c bonus_error.c bonus_op_push.c
SOURCES_BONUS	+=	bonus_op_rrotate.c bonus_operator.c bonus_utils.c
SOURCES_BONUS	+=	bonus_utils_mem.c bonus_main.c bonus_op_rotate.c
SOURCES_BONUS	+=	bonus_op_swap.c bonus_parser.c bonus_utils_data.c

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

OBJ_DIR			=	objects

HEADER			=	$(SOURCES_DIR)/push_swap.h
HEADER_BONUS	=	$(BONUS_DIR)/bonus_checker.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
BONUS_FILES		=	$(addprefix $(BONUS_DIR)/, $(SOURCES_BONUS))

OBJECTS			=	$(SOURCES:$(SOURCES_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJECTS_BONUS	=	$(BONUS_FILES:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	push_swap
NAME_BONUS		=	checker

CC				=	clang
RM				=	rm -rf

CFLAGS			=	-Wall -Wextra -Werror -g3

$(OBJ_DIR)/%.o:		$(SOURCES_DIR)/%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c $(HEADER_BONUS)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				$(NAME_BONUS)

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJECTS) $(HEADER)
					$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(NAME_BONUS):		$(LIBFT) $(OBJ_DIR) $(OBJECTS_BONUS) $(HEADER_BONUS)
					$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):
					$(MAKE) -j16 -C $(LIBFT_PATH) bonus

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

.PHONY:				all clean fclean re libft bonus
