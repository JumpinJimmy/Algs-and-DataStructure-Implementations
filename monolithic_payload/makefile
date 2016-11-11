
CXX ?= g++
OPT = -g
CFLAGS = -Wall -std=c++1y -c $(OPT)
LFLAGS = -Wall -std=c++1y $(OPT)
INC_DIR = includes/
LIBOBJS = file_handler.o max_stack.o circular_queue.o queue_stacks.o
LOCALOBJS = $(LIBOBJS) main.o

all : mono_payload_test
.PHONY : all

mono_payload_test: $(LOCALOBJS)
	$(CXX) $(LFLAGS) $(LOCALOBJS) -o mono_payload_test

main.o: main.cc includes/file_handler.h includes/max_stack.h
	$(CXX) $(CFLAGS) main.cc

max_stack.o: includes/max_stack.h max_stack.cc
	$(CXX) $(CFLAGS) max_stack.cc

circular_queue.o: includes/circular_queue.h circular_queue.cc
	$(CXX) $(CFLAGS) circular_queue.cc

queue_stacks.o: includes/queue_stacks.h queue_stacks.cc
	$(CXX) $(CFLAGS) queue_stacks.cc

file_handler.o: includes/queue_stacks.h includes/circular_queue.h includes/bst_node_prototype.h includes/max_stack.h includes/file_handler.h file_handler.cc
	$(CXX) $(CFLAGS) file_handler.cc

clean:
	rm -f *.o
	rm -f mono_payload_test