# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I. -fsanitize=address
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g  -fsanitize=address
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
#PROGS = test_nodeset
PROGS = test_dijkstra

all: $(PROGS)


#test_graph_small: Node.o Edge.o test.o test_graph_small.o
#test_nodeset:  Node.o Edge.o NodeSet.o test_nodeset.o
test_dijkstra:  Node.o NodeSet.o test_dijkstra.o Edge.o


# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o *.d $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
