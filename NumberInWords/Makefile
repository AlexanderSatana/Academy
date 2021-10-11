CXX := g++
CXX_FLAGS := -std=c++17 

BIN := bin
INCLUDE := src
SRC := src

EXECUTABLE := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)


$(BIN)/$(EXECUTABLE): $(SRC)/*/*.cpp $(SRC)/main.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	rm -fr $(BIN)/*