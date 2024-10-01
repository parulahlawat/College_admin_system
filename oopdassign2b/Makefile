# Variables
CXX = g++
CXXFLAGS = -std=c++11 -pthread

# All the source files
SRCS = main.cpp LibraryItem.cpp Book.cpp Journals.cpp PublicationRank.cpp User.cpp functions.cpp classFunctions.cpp

# Output executable
TARGET = library_app

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the project
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean the build directory
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean