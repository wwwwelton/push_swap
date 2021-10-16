LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=

SOURCES_BONUS	=	checker.c debug.c error.c main.c parser.c
SOURCES_BONUS	+=	utils.c utils_data.c utils_mem.c

SOURCES_DIR		=	sources
BONUS_DIR		=	sources_bonus

OBJ_DIR			=	objects

HEADER			=	$(SOURCES_DIR)/
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

normb:
					clear && norminette $(BONUS_FILES) $(HEADER_BONUS)
runb:
					clear && make bonus && ./checker 1 2 3 4 5

runbe:
					clear && make bonus && ./checker 1 2 3 4 a

runbv1:
					clear && make bonus && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./checker 1 2 3 4 5

runbv2:
					clear && make bonus && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./checker 1 2 3 4 a

runbv3:
					clear && make bonus && valgrind -q --leak-check=full --show-leak-kinds=all -s --error-exitcode=1 --track-origins=yes ./checker 1 2 3 4 1

.PHONY:				all clean fclean re libft bonus
