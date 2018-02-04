CC=g++ 
CFLAGS=-std=c++11
LDFLAGS=-lavapi 

  
MKDIR_P = mkdir -p
LIB_PATH = ${PWD}/Avapi
SRCS = $(wildcard *.cpp)
PROGS = $(patsubst %.cpp,%,$(SRCS))

BINDIR := ${PWD}/Bin/


.PHONY: all
all: obj_dir $(PROGS) 

obj_dir:
	${MKDIR_P} $(BINDIR)  

%: %.cpp
	$(CC) -L ${LIB_PATH} $(CFLAGS) -o $(BINDIR)/$@ $< $(LDFLAGS)

clean: 
	rm -f  $(BINDIR)/*

