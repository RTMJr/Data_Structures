CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS = -Wall
CXXFLAGS = -pedantic-errors
CXXFLAGS = -g
LDLIBS =

OBJS = hashtable.o main.o
SRCS = hashtable.cpp main.cpp
HEADERS = hashtable.hpp

#target: prerequisites
#    recipe

main: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main 

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp) 



