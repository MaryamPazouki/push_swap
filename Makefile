NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = srcs/

SRC_1 = sources/push_swap/main.c \

SRC_2 =	sources/ft_check_sorted\
		sources/ft_error_print.c\
		sources/ft_find_position.c\
		sources/ft_find_target.c\
		sources/ft_free_stack.c\
		sources/ft_max_min.c\
		sources/ft_optimal_cost.c\
		sources/ft_preprocessing.c\
		sources/sort3.c\
		sources/ft_sort.c\
		sources/list_utils_libft.c\
		sources/move.c\
		sources/move_cost_utils.c\
		sources/move_utils.c\
		


OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}


all: ${NAME}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus