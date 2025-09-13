
CXX=g++-14
CXXFLAGS=-O2

all: rpn-eval

rebuild: clean all

rpc-eval: rpn-eval.cpp
	$(CXX) $(CXXFLAGS)-o rpn-eval rpn-eval.cpp

clean:
	rm rpn-eval
