CXX ?= g++-14
CXXFLAGS ?= -O2 -I./src
LDFLAGS ?= -lgtest -lgtest_main -pthread

all: text-editor 

text-editor: src/text_editor.cpp src/main.cpp 
	$(CXX) $(CXXFLAGS) -o text-editor src/text_editor.cpp src/main.cpp

text-editor-tests: tests/tests.cpp src/text_editor.cpp
	$(CXX) $(CXXFLAGS) -o text-editor-tests tests/tests.cpp src/text_editor.cpp $(LDFLAGS)

test: text-editor-tests
	./text-editor-tests

clean: 
	rm text-editor text-editor-tests

rebuild: clean all

.PHONY: all test clean

