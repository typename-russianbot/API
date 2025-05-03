# Compiler #
CXX = g++ 
CXX_FLAGS = -g -Wall -Wextra -std=c++17 

# Program Settings #
SOURCE = source/main.cpp source/master.cpp source/Board.cpp source/Tile.cpp source/Pawn.cpp source/TextBox.cpp source/Button.cpp source/Player.cpp source/PrototypeWrapper.cpp source/MainWindow.cpp source/GameWindow.cpp # Source Files #
OBJECTS = $(patsubst source/%.cpp, build/%.o, $(SOURCE)) # Object Files #
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
	mkdir -p $(BUILD)	
	$(CXX) $(CXX_FLAGS) -c $< -o $@ 
