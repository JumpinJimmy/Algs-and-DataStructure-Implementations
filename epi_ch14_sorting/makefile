
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LLIST_INC= ../epi_ch8_linkedlists/includes/
LIBOBJS = chap_fourteen.o
LOCALOBJS = $(LIBOBJS) main.o

all : ch14_test
.PHONY : all

ch14_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o ch14_test

main.o: main.cc $(INC_DIR)chap_fourteen.h
	$(CXX) $(CFLAGS) main.cc

chap_fourteen.o: $(LLIST_INC)linked_list_prototype.h $(INC_DIR)chap_fourteen.h chap_fourteen.cc
	$(CXX) $(CFLAGS) chap_fourteen.cc

clean:
	rm -f *.o
	rm -f ch14_test