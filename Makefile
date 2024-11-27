# Project Name
NAME = push_swap

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Paths
SRC_DIR = sources/
OBJ_DIR = obj/
INCLUDES = -I includes/ -I libft/
LIBFTDIR = libft/
LIBFT = -L $(LIBFTDIR) -lft

# Source Files
SRC = $(SRC_DIR)main.c \
      $(SRC_DIR)ft_check_sorted.c \
      $(SRC_DIR)ft_error_print.c \
      $(SRC_DIR)ft_find_position.c \
      $(SRC_DIR)ft_find_target.c \
      $(SRC_DIR)ft_free_stack.c \
      $(SRC_DIR)ft_max_min.c \
      $(SRC_DIR)ft_optimal_cost.c \
      $(SRC_DIR)ft_preprocessing.c \
      $(SRC_DIR)sort3.c \
      $(SRC_DIR)ft_sort.c \
      $(SRC_DIR)list_utils_libft.c \
      $(SRC_DIR)move.c \
      $(SRC_DIR)move_cost_utils.c \
      $(SRC_DIR)move_utils.c

# Object Files
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Default Target
all: $(NAME)

# Build Executable
$(NAME): $(OBJ)
	@echo "Compiling libft..."
	@make -C $(LIBFTDIR)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

# Compile .o Files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean Object Files
clean:
	@echo "Cleaning object files..."
	$(RM) -r $(OBJ_DIR)
	@make -C $(LIBFTDIR) clean

# Full Clean (Object Files and Executable)
fclean: clean
	@echo "Removing $(NAME)..."
	$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean

# Rebuild Everything
re: fclean all

# Phony Targets
.PHONY: all clean fclean re
