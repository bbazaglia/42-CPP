NAME = PmergeMe

CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra 
INCLUDES = -I include

VPATH = src
FILES = main.cpp \
        PmergeMe.cpp
                
OBJ_DIR = obj
OBJ_DEBUG_DIR = obj_debug

OBJS = $(FILES:%.cpp=$(OBJ_DIR)/%.o)
DEBUG_OBJS = $(FILES:%.cpp=$(OBJ_DEBUG_DIR)/%.o)

DEBUG_FLAGS = -DDEBUG
DEBUG_NAME = $(NAME)_debug

all: $(NAME)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(DEBUG_NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

$(OBJ_DEBUG_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ && printf "Compiling (Debug): $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(DEBUG_NAME): $(DEBUG_OBJS)
	@$(CC) $(CFLAGS) $(DEBUG_OBJS) -o $(DEBUG_NAME)

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_DEBUG_DIR)

fclean: clean
	@rm -rf $(NAME) $(DEBUG_NAME)

re: fclean all

.PHONY: all clean fclean re debug
