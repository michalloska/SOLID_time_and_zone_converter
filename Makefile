CXX=g++ -std=c++17
DEP_FLAGS=-MMD
DEP_FLAGS+=-MP
CXXFLAGS+=-g
CXXFLAGS+=-Wall
CXXFLAGS+=$(DEP_FLAGS)
MAIN=Executable
SRC=$(wildcard *.cpp)
SRC+=$(wildcard ./src/*.cpp)
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

all: $(MAIN)

$(MAIN): $(OBJ)
		$(CXX) $? -o $@

$(OBJ): $(SRC)
		$(CXX) $(CXXFLAGS) -I. -c $*.cpp -o $@

.PHONY: clean run backup cB

clean:
	rm -f $(MAIN) $(OBJ) $(DEP)

run: $(MAIN)
	./$(MAIN)

backup:
	if [ -d "./backup" ]; then rm -r backup; fi
	mkdir backup
	cp $(SRC) backup
	cp *.h backup

cB:
	rm -r backup

class: 
	read -p "Enter Class Name:" name; \
	touch $$name.cpp; \
	printf "#include \""$$name.h"\"\n\n#include <iostream>\n\n" > $$name.cpp; \
	touch $$name.h; \
	printf "#pragma once\n\nclass "$$name"{\n\npublic:\n\n};\n" > $$name.h

-include $(DEP)
