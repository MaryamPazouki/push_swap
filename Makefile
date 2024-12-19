# Project Name
NAME = push_swap

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Paths
SRC_DIR = sources/
OBJ_DIR = obj/
INCLUDES = -I includes/

# Source Files
SRC = $(SRC_DIR)push_swap.c \
      $(SRC_DIR)ft_check_sorted.c \
      $(SRC_DIR)ft_error_print.c \
      $(SRC_DIR)ft_find_position.c \
      $(SRC_DIR)ft_find_target.c \
      $(SRC_DIR)ft_free_stack.c \
      $(SRC_DIR)ft_max_min.c \
      $(SRC_DIR)ft_optimal_cost.c \
      $(SRC_DIR)ft_preprocessing.c \
      $(SRC_DIR)ft_sort_3.c \
      $(SRC_DIR)ft_sort_main.c \
      $(SRC_DIR)libft_utils_split.c \
      $(SRC_DIR)libft_utils_split_II.c \
      $(SRC_DIR)libft_utils_list.c \
      $(SRC_DIR)libft_utils_list_II.c \
      $(SRC_DIR)move.c \
      $(SRC_DIR)moves_cost_utils.c \
      $(SRC_DIR)move_push.c\
      $(SRC_DIR)move_rotate.c\
      $(SRC_DIR)move_reverse.c\
      $(SRC_DIR)move_swap.c

# Object Files
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Default Target
all: $(NAME)

# Build Executable
$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Compile .o Files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean Object Files
clean:
	@echo "Cleaning object files..."
	$(RM) -r $(OBJ_DIR)

# Full Clean (Object Files and Executable)
fclean: clean
	@echo "Removing $(NAME)..."
	$(RM) $(NAME)

# Rebuild Everything
re: fclean all

leak: re
	valgrind --leak-check=full ./push_swap

# Phony Targets
.PHONY: all clean fclean re
