CC=g++
CFLAGS=-c -Wall -pthread -Ilibs
SOURCES=factorial.h
INCLUDE_PATHS=libs
LIBRARIES=-L./libs -lprometheus-cpp-core -lprometheus-cpp-pull -lprometheus-cpp-push -lz
MAIN=main.cpp $(SOURCES)
TEST=tests/test.cpp $(SOURCES)
OBJECTS_MAIN=$(MAIN:.cpp=.o)
OBJECTS_TEST=$(TEST:.cpp=.o)
EXECUTABLE_MAIN=../usr/bin/factorial
EXECUTABLE_TEST=../usr/bin/factorial_test

all: $(MAIN) $(EXECUTABLE_MAIN)

test: $(TEST) $(EXECUTABLE_TEST)

$(EXECUTABLE_MAIN): $(OBJECTS_MAIN)
	$(CC) $(OBJECTS_MAIN) -o $@ $(LIBRARIES)

$(EXECUTABLE_TEST): $(OBJECTS_TEST)
	$(CC) $(OBJECTS_TEST) -o $@ $(LIBRARIES)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE_MAIN) $(EXECUTABLE_TEST)
