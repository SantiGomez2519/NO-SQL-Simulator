# Define the compiler
CXX = g++

# Define the compiler flags
CXXFLAGS = -Wall -g

# Define the target executable
TARGET = NOSQLDatabase

# Define the source files
SRCS = main.cpp MotorDatosNoSQL.cpp NoSQLParser.cpp

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