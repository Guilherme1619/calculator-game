# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -arch arm64
RAYLIB_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib \
               -framework CoreVideo -framework IOKit -framework Cocoa -framework OpenGL

# Source files
OPENWINDOW_SRC = main-code/openwindow.cpp

# Executables
OPENWINDOW = openwindow

# Default target
all: $(OPENWINDOW)

# Build openwindow
$(OPENWINDOW): $(OPENWINDOW_SRC)
	$(CXX) $(CXXFLAGS) $(OPENWINDOW_SRC) -o $(OPENWINDOW) $(RAYLIB_FLAGS)

# Run openwindow
run-openwindow: $(OPENWINDOW)
	./$(OPENWINDOW)

# Clean compiled files
clean:
	rm -f $(OPENWINDOW)

.PHONY: all clean run-openwindow