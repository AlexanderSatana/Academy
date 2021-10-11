CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb 

BIN     := bin
SRC     := src
INCLUDE := src

# LIBRARIES   :=
EXECUTABLE  := main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/ChessBoard/*.cpp $(SRC)/Canvas/*.cpp $(SRC)/main.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*