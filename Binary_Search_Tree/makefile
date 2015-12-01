CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS = -Wall
CXXFLAGS = -pedantic-errors
CXXFLAGS = -g
LDLIBS =

OBJS = bstree.o main.o
SRCS = bstree.cpp main.cpp
HEADERS = bstree.hpp

#target: prerequisites
#    recipe

main: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main 

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp) 



