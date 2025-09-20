
CXX ?= g++-14
CXXFLAGS ?= -O2 -Wall -Wextra -Werror
LDFLAGS ?=

all: rpn-eval

rebuild: clean all

rpc-eval: rpn-eval.cpp
	$(CXX) $(CXXFLAGS) -o rpn-eval rpn-eval.cpp

clean:
	rm rpn-eval output.txt

test: rpn-eval
	./rpn-eval

.PHONY: all test clean
