# Compiler #
CXX = g++ 
CXX_FLAGS = -g -Wall -Wextra -std=c++17 

# Program Settings #
SOURCE := $(shell find source -name '*.cpp') # Auto-Find Source Files #
OBJECTS := $(patsubst source/%.cpp, build/%.o, $(SOURCE)) # Object Files #
BUILD = build # Build Files #
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system # Dependencies #
TARGET = run # Executable #

# Operations #
all: $(TARGET)

clean: 
	rm -rf $(TARGET) $(BUILD)
	clear

$(TARGET): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) $(SFML_LIBS) -o $(TARGET) 

build/%.o: source/%.cpp
	mkdir -p $(BUILD) $(dir $@) 
	$(CXX) $(CXX_FLAGS) -c $< -o $@ 
