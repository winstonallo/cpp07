NAME = ft_ssl

OBJ_DIR = build
SRC_DIR = src
INC_DIR = inc
LIBFT_DIR = libft

BLOCK_SIZE=$(shell stat -fc %s .)

SRCS = 	main.cpp \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

HEADERS = $(wildcard $(INC_DIR)/*.h) $(wildcard $(LIBFT_DIR)/src/**/*.h)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

CC = cc
CFLAGS = -std=c++98 -DFS_BLOCK_SIZE=${BLOCK_SIZE} -Wall -Wextra -Werror \
	-I$(INC_DIR) 
LDFLAGS = $(LIBFT_FLAGS) 

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

prof:
	FILE_NAME="/tmp/.out" ./tests/generate_random_file.sh
	make fclean
	make CFLAGS="${CFLAGS} -pg -g"
	valgrind --tool=callgrind ./ft_ssl ${ALGO} /tmp/.out
	callgrind_annotate callgrind.out.* > ${OUTFILE}
	rm callgrind.out.* gmon.out

debug: CFLAGS = -DFS_BLOCK_SIZE=${BLOCK_SIZE} -Wall -Wextra -Werror -g \
	-I$(INC_DIR) 
debug: all

.PHONY: all clean fclean re debug
