# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

# SYMBOLS
INFO = $(WHITE)[$(BLUE)ℹ️$(WHITE)] $(NOC)
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)

# Leaks cmd
LEAKS_CMD = valgrind --leak-check=yes

# Binary
NAME=philo

# Path
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INCDIR = includes

# Name
SRC_NAME =	main.c \
			parsing/parse.c \
			threads/thread_validator.c \
			philosophers/new.c \
			philosophers/clear.c \
			philosophers/state.c \
			philosophers/live.c \
			philosophers/fork.c \
			philosophers/eat.c \
			utils/utils.c \
			utils/parsing_utils.c

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror -pthread

all: obj $(NAME)

obj:
	@echo "$(INFO)Creating objects folder... $(NOC)"
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/philosophers
	@mkdir -p $(OBJ_PATH)/threads
	@mkdir -p $(OBJ_PATH)/parsing
	@mkdir -p $(OBJ_PATH)/utils
	@echo "$(SUCCESS)Objects folder created successfully$(NOC)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	@echo "$(INFO)Building $(NAME)...$(NOC)"
	@$(CC) $(OBJ) $(FT_LNK) $(GLIB_LNK) $(MLX_LNK) -o $@
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"

clean:
	@echo "$(INFO)Deleting .o files...$(NOC)"
	@rm -rf $(OBJ_PATH)
	@rm -rf $(NAME)
	@echo "$(SUCCESS).o files deleted successfully!$(NOC)"

fclean: clean
	@echo "$(INFO)Deleting $(NAME)...$(NOC)"
	@rm -rf $(NAME)
	@echo "$(SUCCESS)$(NAME) deleted successfully!$(NOC)"

re: fclean all

leaks: $(NAME)
	$(LEAKS_CMD) ./$(NAME) 10 400 100 100 5

run: $(NAME)
	@./$(NAME) 9 400 100 100 5

.PHONY:			all clean fclean re leaks run