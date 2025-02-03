NAME = ex.bin

OBJ_DIR = build
SRC_DIR = src
INC_DIR = inc

BLOCK_SIZE=$(shell stat -fc %s .)

SRCS = 	main.cpp whatever.cpp

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

HEADERS = $(wildcard $(INC_DIR)/*.h) $(wildcard $(LIBFT_DIR)/src/**/*.h)

CC = c++
CFLAGS = -std=c++98 -DFS_BLOCK_SIZE=${BLOCK_SIZE} -Wall -Wextra -Werror -I$(INC_DIR) 

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

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
