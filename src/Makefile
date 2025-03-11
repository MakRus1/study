CC=g++
CFLAGS=-c -Wall
SOURCES=factorial.h
MAIN=main.cpp $(SOURCES)
TEST=tests/test.cpp $(SOURCES)
OBJECTS_MAIN=$(MAIN:.cpp=.o)
OBJECTS_TEST=$(TEST:.cpp=.o)
EXECUTABLE_MAIN=../usr/bin/factorial
EXECUTABLE_TEST=../usr/bin/factorial_test

all: $(MAIN) $(EXECUTABLE_MAIN)

test: $(TEST) $(EXECUTABLE_TEST)

$(EXECUTABLE_MAIN): $(OBJECTS_MAIN)
	$(CC) $(OBJECTS_MAIN) -o $@

$(EXECUTABLE_TEST): $(OBJECTS_TEST)
	$(CC) $(OBJECTS_TEST) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE_MAIN) $(EXECUTABLE_TEST)
