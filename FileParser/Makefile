CXX := g++
CXX_FLAGS = -std=c++17 -ggdb

BIN := bin
SRC := src
INCLUDE := src

EXECUTABLE := main

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*/*.cpp $(SRC)/main.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $ $@ $(LIBRARIES)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

clean:
	rm -fr $(BIN)/*