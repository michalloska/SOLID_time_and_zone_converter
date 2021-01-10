CXX=g++ -std=gnu++2a
DEP_FLAGS=-MMD
DEP_FLAGS+=-MP
CXXFLAGS+=-g
CXXFLAGS+=-Wall
CXXFLAGS+=$(DEP_FLAGS)
LXXFLAGS= -std=gnu++2a -I h -pthread
MAIN=Executable
SRC=$(wildcard *.cpp)
SRC+=$(wildcard ./src/*.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

TEST_OBJECTS = ./tests/mainGTest.o ./tests/TimeTestSuite.o ./tests/TimeZoneTestSuite.o ./tests/TimeZoneConverterTestSuite.o 
GOOGLE_TEST_SRC=$(wildcard ./tests/*.cpp)
TEST_DEP=$(GOOGLE_TEST_SRC:.cpp=.d)
GTEST = ../googletest-master/build/lib/libgtest.a
GTEST_EXEC = execTest.out
all: $(MAIN)

$(MAIN): $(OBJ)
		$(CXX) $? -o $@

$(OBJ): $(SRC)
		$(CXX) $(CXXFLAGS) -I. -c $*.cpp -o $@

.PHONY: clean run backup cB

clean:
	rm -f $(MAIN) $(OBJ) $(TEST_OBJECTS) $(TEST_DEP) $(DEP)

run: $(MAIN)
	./$(MAIN) $(TIME) $(SRCT) $(DESTT)

backup:
	if [ -d "./backup" ]; then rm -r backup; fi
	mkdir backup
	cp $(SRC) backup
	cp *.h backup

test: $(TEST_OBJECTS)
	$(CXX) $(LXXFLAGS) -o execTest.out $(TEST_OBJECTS) $(wildcard ./src/*.cpp) $(GTEST)
	./execTest.out

run_test: 
	./execTest.out

$(TEST_OBJECTS): $(GOOGLE_TEST_SRC) $(SRC)
	$(CXX) $(CXXFLAGS) -Iinclude -Itests -c $*.cpp -o $@

cB:
	rm -r backup

class: 
	read -p "Enter Class Name:" name; \
	touch $$name.cpp; \
	printf "#include \""$$name.h"\"\n\n#include <iostream>\n\n" > $$name.cpp; \
	touch $$name.h; \
	printf "#pragma once\n\nclass "$$name"{\n\npublic:\n\n};\n" > $$name.h

-include $(DEP)
