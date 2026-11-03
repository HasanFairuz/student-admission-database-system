CXX ?= g++
CXXFLAGS ?= -std=c++11 -O2 -Wall -Wextra
CPPFLAGS ?= -Iinclude
TARGET := admission-system
SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:.cpp=.o)

.PHONY: all run clean
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

# Original code expects the input filenames in the working directory.
run: $(TARGET)
	cd data && ../$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
