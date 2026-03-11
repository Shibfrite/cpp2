NAME		:= ex00

CC			:= c++
CFLAGS		:= -Wall -Wextra -Werror -g -O0 -std=c++98 -pedantic
RM			:= rm -rf

INC_DIR		:= includes
SRC_DIR		:= sources
OBJ_DIR		:= objects

SRC_FILES	:= main.cpp Serializer.cpp
SRC_PREFIX	:= $(SRC_DIR)/
SRCS		:= $(addprefix $(SRC_PREFIX),$(SRC_FILES))
OBJS		:= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
INC			:= -I$(INC_DIR)
DIRS		:= $(INC_DIR) $(SRC_DIR) $(OBJ_DIR)

all:		$(NAME)

$(NAME):	$(OBJS)
	echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -o $@
	echo "$(NAME) created successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(DIRS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(DIRS):
	mkdir -p $@
	echo "Created directory: $@"

clean:
	echo "Cleaning object files..."
	$(RM) $(OBJ_DIR)
	echo "Object files cleaned."

fclean: clean
	echo "Cleaning executable and library..."
	$(RM) $(NAME)
	echo "Executable and library cleaned."

re: fclean all

#end the script updating the makefile
kill:
	pkill -f ".add_src.bash"

.SILENT:
.PHONY: all clean fclean re
