
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = string_probs.o
LOCALOBJS = $(LIBOBJS) main.o

all : string_test
.PHONY : all

string_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o string_test

main.o: main.cc includes/string_probs.h
	$(CXX) $(CFLAGS) main.cc

string_probs.o: includes/string_probs.h string_probs.cc
	$(CXX) $(CFLAGS) string_probs.cc

clean:
	rm -f *.o
	rm -f string_test