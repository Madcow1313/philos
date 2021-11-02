NAME = philosophers

SOURCE = eat.c \
		fill_main_struct.c \
		ft_atoi_long.c \
		init_func.c \
		main.c \
		start_dinner.c \
		start_gathering.c

HEADER = philosophers.h

OBJECTS = $(SOURCE:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECTS) $(HEADER)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
		rm -rf $(OBJECTS)

fclean:
		rm -rf $(OBJECTS) $(NAME)
