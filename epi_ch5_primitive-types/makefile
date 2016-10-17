
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = chapter_five.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch5_test
.PHONY : all

ch5_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch5_test

main.o: main.cc includes/chapter_five.h
	$(CXX) $(CFLAGS) main.cc

chapter_five.o: includes/chapter_five.h chapter_five.cc
	$(CXX) $(CFLAGS) chapter_five.cc

clean:
	rm -f *.o
	rm -f ch5_test