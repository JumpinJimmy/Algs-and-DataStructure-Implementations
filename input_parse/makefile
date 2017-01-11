
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = dummy_class.o
LOCALOBJS = $(LIBOBJS) main.o

all : input_parse
.PHONY : all

input_parse: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o input_parse

main.o: main.cc includes/dummy_class.h
	$(CXX) $(CFLAGS) main.cc

dummy_class.o: includes/dummy_class.h dummy_class.cc
	$(CXX) $(CFLAGS) dummy_class.cc

clean:
	rm -f *.o
	rm -f input_parse