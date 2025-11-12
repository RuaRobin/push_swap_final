NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = -I. -I./libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
BONUS_NAME = checker
SRCS = main.c creation.c operations.c operations2.c parseinput.c auxi.c findings.c totop.c push_swap.c
OBJS = $(SRCS:.c=.o)
BONUS_DIR = ./checker_bonus
BONUS_SRCS = $(BONUS_DIR)/main.c \
             $(BONUS_DIR)/creationbonus.c \
             $(BONUS_DIR)/operationsbonus.c \
             $(BONUS_DIR)/checking.c \
             $(BONUS_DIR)/parsing_input_bonus.c \
             $(BONUS_DIR)/get_next_line.c \
             $(BONUS_DIR)/get_next_line_utils.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)
bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_DIR)/checker.h $(BONUS_DIR)/get_next_line.h
	$(CC) $(CFLAGS) $(INCLUDES) -I$(BONUS_DIR) -c $< -o $@
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY: all bonus clean fclean re