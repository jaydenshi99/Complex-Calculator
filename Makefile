# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Iinclude -g

# Source files and output
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = mandelbrot

# Build target
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to create object files
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean rule to remove generated files
clean:
	rm -f $(OBJ) $(TARGET)