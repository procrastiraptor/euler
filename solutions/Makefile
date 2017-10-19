.PHONY: clean

CXXFLAGS += -I..

sources = $(wildcard *.cpp)
objects = $(sources:.cpp=.o)

lib$(libname).a: $(objects)
	$(AR) $(ARFLAGS) $@ $?

map.o: list.h members.h

list.h: $(sources)
	./genlist >$@

members.h: list.h
	./genmembers $^ >$@

clean:
	$(RM) *.o lib$(libname).a list.h members.h
