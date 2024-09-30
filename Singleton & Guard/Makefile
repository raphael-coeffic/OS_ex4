# Definition of the compiler and options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -pthread

# Name of the executable
TARGET = my_program

# Object files
OBJS = Singleton.o Guard.o main.o

# Default rule to build the executable
all: $(TARGET)

# Linking the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilation of .cpp files into .o files
Singleton.o: Singleton.cpp Singleton.hpp
	$(CXX) $(CXXFLAGS) -c Singleton.cpp

Guard.o: Guard.cpp
	$(CXX) $(CXXFLAGS) -c Guard.cpp

main.o: main.cpp Singleton.hpp Guard.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Rule to run the program after compilation
run: all
	./$(TARGET)
