# Compiler
CC = c++

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -std=c++98 -Iinclude

# Target executable
NAME = account

# Source files
SRC = Account.cpp tests.cpp

# Object directory
OBJ_DIR = obj

# Object files
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# Default target
all: $(NAME)

# Link the executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "Executable created: $(NAME)"

# Compile source files into object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned object files"

# Clean object files and executable
fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned executable"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re