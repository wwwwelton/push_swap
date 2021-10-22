LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	algo_a.c algo_b.c algo_utils.c error.c main.c parser.c
SOURCES_FILES	+=	push_swap.c utils.c utils_data.c utils_mem.c

SOURCES_BONUS	=	checker.c error.c main.c parser.c
SOURCES_BONUS	+=	utils.c utils_data.c utils_mem.c operator.c
SOURCES_BONUS	+=	op_swap.c op_push.c op_rotate.c op_rrotate.c

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

OBJ_DIR			=	objects

HEADER			=	$(SOURCES_DIR)/push_swap.h
HEADER_BONUS	=	$(BONUS_DIR)/checker.h

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
					$(MAKE) -C $(LIBFT_PATH) bonus

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					$(MAKE) -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) $(NAME) $(NAME_BONUS)

re:					fclean all

norm:
					clear && norminette $(SOURCES) $(HEADER)

normb:
					clear && norminette $(BONUS_FILES) $(HEADER_BONUS)

run:
					clear && make && ./push_swap 1 2 3 4 5

runv:
					clear && make && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./push_swap 1 2 3 4 5

runv2:
					clear && make && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./push_swap 5 4 3 2 1

runb:
					clear && make bonus && ./checker 1 2 3 4 5

runbe:
					clear && make bonus && ./checker 1 2 3 4 a

runbv1:
					clear && make bonus && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./checker 4 3 6 5 7 0 8 9 2 1

runbv2:
					clear && make bonus && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./checker 1 2 3 4 a

runbv3:
					clear && make bonus && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./checker 1 2 3 4 1

.PHONY:				all clean fclean re libft bonus
