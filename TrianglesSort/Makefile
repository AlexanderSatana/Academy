CXX 		:= g++
CXX_FLAGS 	:= -std=c++17 -ggdb

BIN 	:= bin
INCLUDE := include
SRC 	:= src

EXECUTABLE := main

all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/main.cpp $(SRC)/DataReader/*.cpp $(SRC)/DataHandler/*.cpp $(SRC)/DataDrawer/*.cpp $(SRC)/Utils/*.cpp $(SRC)/Object/*.cpp 
	$(CXX) $(CXX_FLAGS) -I$(SRC) $^ -o $@ $(LIBRARIES)

clean:
	rm -rf $(BIN)/*