##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## makefile
##

NAME	= ../mysh      \

CC	= gcc

RM	= rm -rf

SRCS	= ./main.c \
		  ./order_sorting.c \
		  ./output.c \
		  ./cd_file.c \
		  ./path.c \

OBJS	= $(SRCS:.c=.o)
CFLAGS += -W -Wall -Wextra -pedantic
LDFLAGS += -I./include -L../lib/my -lmy
DEBUGFLAGS = -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re