CFLAGS = -Wall -Wextra -Werror

SRCS = ft_push_swap_utils.c ft_push_swap.c radix_utils.c radix.c stack_ops.c validation.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

HEADER = ft_push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	cc $(CFLAGS) -I$(HEADER) $(OBJS) -o $@

# $(OBJS): %.o: %.c $(HEADER)
# 	cc $(CFLAGS) -I$(HEADER) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
