# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -I./include -Wall -std=c++11

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
TARGET = $(BIN_DIR)/compress

# Main rule
all: $(TARGET)

# Ensure directories exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Compilation rule
$(TARGET): $(BIN_DIR) $(OBJ_DIR) $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

# Object file compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ_DIR)/*.o $(TARGET)
	rm -rf $(BIN_DIR) $(OBJ_DIR)

# Run rule
run: $(TARGET)
	./$(TARGET)