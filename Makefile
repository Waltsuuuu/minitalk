# === Compiler & Flags ===
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -Iprintf

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
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# === PRINTF ===
PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# === Objects ===
OBJS = $(SERVER_OBJS) $(CLIENT_OBJS)
.SECONDARY: $(OBJS)

# === Build Targets ===
all: $(LIBFT_LIB) $(PRINTF_LIB) $(SERVER) $(CLIENT)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(SERVER): $(SERVER_OBJS) $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT): $(CLIENT_OBJS) $(LIBFT_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# === Cleanup ===
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
