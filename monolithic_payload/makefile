
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = file_handler.o
LOCALOBJS = $(LIBOBJS) main.o

all : mono_payload_test
.PHONY : all

mono_payload_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o mono_payload_test

main.o: main.cc includes/file_handler.h
	$(CXX) $(CFLAGS) main.cc

file_handler.o: includes/file_handler.h file_handler.cc
	$(CXX) $(CFLAGS) file_handler.cc

clean:
	rm -f *.o
	rm -f mono_payload_test