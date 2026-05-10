#compilers
CC = gcc
CXX = g++

#compilation flags — release por defecto
CFLAGS = -Wall -O2
CXXFLAGS = -Wall -std=c++23 -O2

#debug flags
CFLAGS_DBG = -Wall -g
CXXFLAGS_DBG = -Wall -std=c++23 -g

LDFLAGS = -lpthread -ldl

#archive name
TARGET = ./output/hibridexe
RS_SRC = src/lib.rs
RS_LIB = ./output/librust_part.a
RS_LIB_DBG = ./output/librust_part_dbg.a
C_OBJ = ./output/funcion.o
CPP_OBJ = ./output/main.o
LINK_OBJ = ./output/linker.o

# ─── RELEASE ───────────────────────────────────────────
.PHONY: all
all: clean $(TARGET)

$(TARGET): $(CPP_OBJ) $(C_OBJ) $(LINK_OBJ) $(RS_LIB)
	$(CXX) $(CPP_OBJ) $(C_OBJ) $(LINK_OBJ) $(RS_LIB) -o $(TARGET) $(LDFLAGS)

$(RS_LIB): $(RS_SRC)
	cargo build --release
	cp target/release/libexperimental.a $(RS_LIB)

$(LINK_OBJ): src/linker.c
	$(CC) $(CFLAGS) -c src/linker.c -o $(LINK_OBJ)

$(C_OBJ): src/funcion.c
	$(CC) $(CFLAGS) -c src/funcion.c -o $(C_OBJ)

$(CPP_OBJ): src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $(CPP_OBJ)

# ─── DEBUG ─────────────────────────────────────────────
.PHONY: debug
debug: clean \
	$(RS_LIB_DBG) \
	$(LINK_OBJ) \
	$(C_OBJ) \
	$(CPP_OBJ)
	$(CXX) $(CPP_OBJ) $(C_OBJ) $(LINK_OBJ) $(RS_LIB_DBG) -o $(TARGET) $(LDFLAGS)

$(RS_LIB_DBG): $(RS_SRC)
	cargo build
	cp target/debug/libexperimental.a $(RS_LIB_DBG)

# ─── CLEAN ─────────────────────────────────────────────
.PHONY: clean
clean:
	rm -f $(RS_LIB) $(RS_LIB_DBG) $(CPP_OBJ) $(C_OBJ) $(LINK_OBJ)
	cargo clean
