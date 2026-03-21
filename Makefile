#compilers
CC = gcc
CXX = g++
RUSTC = rustc 

#compilation flags
CFLAGS = -Wall
CXXFLAGS = -Wall -std=c++23
LDFLAGS = -lpthread -ldl

#archive name
TARGET = hibridexe
RS_SRC = src/lib.rs
RS_LIB = src/librust_part.a
C_OBJ = funcion.o
CPP_OBJ = main.o

# executable definitions
all: $(TARGET)

#linking code
$(TARGET): $(CPP_OBJ) $(C_OBJ) $(RS_LIB)
	$(CXX) $(CPP_OBJ) $(C_OBJ) $(RS_LIB) -o $(TARGET) $(LDFLAGS)

#compile static Rust lib
$(RS_LIB): $(RS_SRC)
	$(RUSTC) --crate-type=staticlib $(RS_SRC) -o $(RS_LIB)

#compile C object 
$(C_OBJ): funcion.c 
	$(CC) $(CFLAGS) -c funcion.c -o $(C_OBJ)

#Compile the main object (C++)
$(CPP_OBJ): main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(CPP_OBJ)

#archive generated cleaning
clean: 
	rm -f $(RS_LIB) *.o