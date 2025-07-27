CC = cc
CFLAGS = -Wall -Werror -Wextra -I../includes
AR = ar
ARFLAGS = rcs

LIB_NAME = libftprintf.a

SOURCES = ft_printf.c \
ft_printf_utils.c \


OBJECTS = $(SOURCES:.c=.o) 

all: $(LIB_NAME)

$(LIB_NAME): $(OBJECTS)
	$(AR) $(ARFLAGS) $(LIB_NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(BONUS_OBJECTS)

fclean:
	rm -rf $(OBJECTS) $(BONUS_OBJECTS) $(LIB_NAME) 

re: fclean all

.PHONY: all clean fclean re bonus
