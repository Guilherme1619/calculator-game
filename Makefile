# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11
RAYLIB_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

# Source files
OPENWINDOW_SRC = main.cpp/openwindow.cpp
CALCULATOR_SRC = main.cpp/calculator.cpp

# Executables
OPENWINDOW = openwindow
CALCULATOR = calculator

# Default target
all: $(OPENWINDOW) $(CALCULATOR)

# Build openwindow
$(OPENWINDOW): $(OPENWINDOW_SRC)
	$(CXX) $(CXXFLAGS) $(OPENWINDOW_SRC) -o $(OPENWINDOW) $(RAYLIB_FLAGS)

# Build calculator
$(CALCULATOR): $(CALCULATOR_SRC)
	$(CXX) $(CXXFLAGS) $(CALCULATOR_SRC) -o $(CALCULATOR)

# Run openwindow
run-window: $(OPENWINDOW)
	./$(OPENWINDOW)

# Run calculator
run-calc: $(CALCULATOR)
	./$(CALCULATOR)

# Clean compiled files
clean:
	rm -f $(OPENWINDOW) $(CALCULATOR)

.PHONY: all clean run-window run-calc



