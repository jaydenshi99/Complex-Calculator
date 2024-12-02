# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Iinclude -std=c++17 -Wall

# Source files
SRC = src/main.cpp src/complex.cpp src/calculator.cpp src/helper.cpp src/other.cpp

# Output executable
TARGET = calc

# Build target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean build files
clean:
	rm -f $(TARGET)