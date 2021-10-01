CC := g++
CXX_FLAGS := -std=c++17 -ggdb -lm

INCLUDE := src
SRC := src
BIN := bin

# LIBRARIES :=
EXECUTABLE := main

all: $(BIN)/$(EXECUTABLE)

run: clean all 
	clear
	./$(BIN)/$(EXECUTABLE)


$(BIN)/$(EXECUTABLE): $(SRC)/DataReader/*.cpp $(SRC)/Envelope/*.cpp $(SRC)/ConditionChecker/*.cpp $(SRC)/main.cpp 
	$(CC) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	rm -rf $(BIN)/*