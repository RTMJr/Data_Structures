CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS = -Wall
CXXFLAGS = -pedantic-errors
CXXFLAGS = -g
LDLIBS =

OBJS = doubly_linked_list.o stack.o main.o
SRCS = doubly_linked_list.cpp stack.cpp main.cpp
HEADERS = doubly_linked_list.hpp stack.hpp

#target: prerequisites
#    recipe

main: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main 

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp) 



