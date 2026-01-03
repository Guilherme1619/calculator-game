# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -arch arm64
RAYLIB_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib \
               -framework CoreVideo -framework IOKit -framework Cocoa -framework OpenGL

# Source files
OPENWINDOW_SRC = main-code/openwindow.cpp
CALCULATOR_SRC = main-code/calculator.cpp

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
run-openwindow: $(OPENWINDOW)
	./$(OPENWINDOW)

# Run calculator
run-calculator: $(CALCULATOR)
	./$(CALCULATOR)

# Clean compiled files
clean:
	rm -f $(OPENWINDOW) $(CALCULATOR)

.PHONY: all clean run-window run-calc