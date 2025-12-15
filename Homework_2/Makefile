CXX ?= g++-14
CXXFLAGS ?= -O2 
LDFLAGS ?=

all: text-editor

rebuild: clean all

rpc-eval: text-editor
	$(CXX) $(CXXFLAGS) -o text-editor text-editor.cpp

clean: 
	rm text-editor

test: text-editor
	echo 0 |./text-editor

.PHONY: all test clean

