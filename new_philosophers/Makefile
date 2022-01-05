NAME = philosophers

SOURCE = check_input.c dining.c eat.c \
			fill_main_struct.c ft_atoi_long.c \
			get_time.c init_staff.c main.c \
			start_gathering.c write_staff.c

HEADER = philosophers.h

OBJECTS = $(SOURCE:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJECTS) $(HEADER)
		$(CC) $(CFLAGS)  -pthread $(OBJECTS) -o $(NAME)

all:	$(NAME)

clean:
		rm -rf $(OBJECTS)

fclean:
		rm -rf $(OBJECTS) $(NAME)

re:		fclean $(NAME)
