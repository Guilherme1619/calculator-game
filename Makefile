# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -arch arm64
RAYLIB_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib \
               -framework CoreVideo -framework IOKit -framework Cocoa -framework OpenGL

# Source files
MAIN_SRC = main.cpp

# Executables
MAIN = main

# Default target
all: $(MAIN)

# Build main
$(MAIN): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) $(MAIN_SRC) -o $(MAIN) $(RAYLIB_FLAGS)

# Run main
run-main: $(MAIN)
	./$(MAIN)

# Clean compiled files
clean:
	rm -f $(MAIN)

.PHONY: all clean run-main