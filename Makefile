# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -std=c++17 -Wall

# Source files
SRC = src/main.cpp src/complex.cpp src/calculator.cpp

# Output executable
TARGET = complex_calculator

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean build files
clean:
	rm -f $(TARGET)