# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Include directories (modify according to your actual include paths)
INCLUDES = -I/usr/include/c++/9

# Source file
SRC = 15_threeSum/main.cc

# Object file
OBJ = $(SRC:.cc=.o)

# Output directory
OUTPUT_DIR = output

# Executable file
EXEC = $(OUTPUT_DIR)/threeSum

# Default target
all: $(EXEC) clean_obj

# Rule to link the executable
$(EXEC): $(OBJ) | $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

# Rule to compile source files into object files
%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create output directory if it doesn't exist
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Clean up object files after build
clean_obj:
	rm -f $(OBJ)

# Clean up all build files
clean: clean_obj
	rm -f $(EXEC)

# Phony targets
.PHONY: all clean clean_obj

