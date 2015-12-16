CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS = -Wall
CXXFLAGS = -pedantic-errors
CXXFLAGS = -g
LDLIBS =

OBJS = graph.o main.o
SRCS = graph.cpp main.cpp
HEADERS = graph.hpp

#target: prerequisites
#    recipe

main: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main 

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp) 



