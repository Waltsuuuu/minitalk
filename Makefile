# === Compiler & Flags ===
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# === Executables ===
SERVER = server
CLIENT = client

# === SERVER ===
SERVER_DIR = src/server
SERVER_SRCS = \
	$(SERVER_DIR)/server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# === CLIENT ===
CLIENT_DIR = src/client
CLIENT_SRCS = \
	$(CLIENT_DIR)/client.c \
	$(CLIENT_DIR)/client_utils.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

# === LIBFT ===
LIBFT_DIR = libft
LIBFT_SRCS = \
	$(LIBFT_DIR)/ft_atoi.c \
	$(LIBFT_DIR)/ft_bzero.c \
	$(LIBFT_DIR)/ft_calloc.c \
	$(LIBFT_DIR)/ft_isalnum.c \
	$(LIBFT_DIR)/ft_isalpha.c \
	$(LIBFT_DIR)/ft_isascii.c \
	$(LIBFT_DIR)/ft_isdigit.c \
	$(LIBFT_DIR)/ft_isprint.c \
	$(LIBFT_DIR)/ft_itoa.c \
	$(LIBFT_DIR)/ft_memchr.c \
	$(LIBFT_DIR)/ft_memcmp.c \
	$(LIBFT_DIR)/ft_memcpy.c \
	$(LIBFT_DIR)/ft_memmove.c \
	$(LIBFT_DIR)/ft_memset.c \
	$(LIBFT_DIR)/ft_putchar_fd.c \
	$(LIBFT_DIR)/ft_putendl_fd.c \
	$(LIBFT_DIR)/ft_putnbr_fd.c \
	$(LIBFT_DIR)/ft_putstr_fd.c \
	$(LIBFT_DIR)/ft_split.c \
	$(LIBFT_DIR)/ft_strchr.c \
	$(LIBFT_DIR)/ft_strdup.c \
	$(LIBFT_DIR)/ft_striteri.c \
	$(LIBFT_DIR)/ft_strjoin.c \
	$(LIBFT_DIR)/ft_strlcat.c \
	$(LIBFT_DIR)/ft_strlcpy.c \
	$(LIBFT_DIR)/ft_strlen.c \
	$(LIBFT_DIR)/ft_strmapi.c \
	$(LIBFT_DIR)/ft_strncmp.c \
	$(LIBFT_DIR)/ft_strnstr.c \
	$(LIBFT_DIR)/ft_strrchr.c \
	$(LIBFT_DIR)/ft_strtrim.c \
	$(LIBFT_DIR)/ft_substr.c \
	$(LIBFT_DIR)/ft_tolower.c \
	$(LIBFT_DIR)/ft_toupper.c \
	$(LIBFT_DIR)/ft_lstadd_back_bonus.c \
	$(LIBFT_DIR)/ft_lstadd_front_bonus.c \
	$(LIBFT_DIR)/ft_lstclear_bonus.c \
	$(LIBFT_DIR)/ft_lstdelone_bonus.c \
	$(LIBFT_DIR)/ft_lstiter_bonus.c \
	$(LIBFT_DIR)/ft_lstlast_bonus.c \
	$(LIBFT_DIR)/ft_lstmap_bonus.c \
	$(LIBFT_DIR)/ft_lstnew_bonus.c \
	$(LIBFT_DIR)/ft_lstsize_bonus.c
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# === PRINTF ===
PRINTF_DIR = printf
PRINTF_SRCS = \
	$(PRINTF_DIR)/ft_printf.c \
	$(PRINTF_DIR)/ft_printf_utils.c
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

# === Objects ===
OBJS = $(SERVER_OBJS) $(CLIENT_OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)

# === Build Targets ===
all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(CLIENT_OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# === Cleanup ===
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
