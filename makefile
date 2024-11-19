# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -Wall -std=c++11

# Define the target executable
TARGET = main

# Define the source files
SRCS = main.cpp

# Default target
all: $(TARGET)

# Rule to compile the source files and create the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean up the generated files
clean:
	rm -f $(TARGET) $(OBJS)
	
# Run the program
run: $(TARGET)
	./$(TARGET)