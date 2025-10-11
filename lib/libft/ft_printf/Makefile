NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC_FILES := ft_printf.c	ft_utils.c	ft_utils2.c
SRCS := $(addprefix src/, $(SRC_FILES))
OBJS := $(SRCS:.c=.o)

INCLUDES := -I lib

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re