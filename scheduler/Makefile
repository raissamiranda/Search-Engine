CC = g++
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/URL.o $(OBJ)/Host.o $(OBJ)/ListaURL.o $(OBJ)/FilaHost.o $(OBJ)/Escalonador.o
HDRS = $(INC)/URL.hpp $(INC)/Host.hpp $(INC)/ListaURL.hpp $(INC)/FilaHost.hpp $(INC)/Escalonador.hpp
CFLAGS = -std=c++11 -Wall -I$(INC) 

EXE = $(BIN)/main

$(BIN)/main: $(OBJS)
	$(CC) -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) -c $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/URL.o: $(HDRS) $(SRC)/URL.cpp
	$(CC) -c $(CFLAGS) -o $(OBJ)/URL.o $(SRC)/URL.cpp

$(OBJ)/Host.o: $(HDRS) $(SRC)/Host.cpp
	$(CC) -c $(CFLAGS) -o $(OBJ)/Host.o $(SRC)/Host.cpp

$(OBJ)/ListaURL.o: $(HDRS) $(SRC)/ListaURL.cpp
	$(CC) -c $(CFLAGS) -o $(OBJ)/ListaURL.o $(SRC)/ListaURL.cpp

$(OBJ)/FilaHost.o: $(HDRS) $(SRC)/FilaHost.cpp
	$(CC) -c $(CFLAGS) -o $(OBJ)/FilaHost.o $(SRC)/FilaHost.cpp

$(OBJ)/Escalonador.o: $(HDRS) $(SRC)/Escalonador.cpp
	$(CC) -c $(CFLAGS) -o $(OBJ)/Escalonador.o $(SRC)/Escalonador.cpp

clean:
	rm -f $(EXE) $(OBJS)