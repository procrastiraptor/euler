.PHONY: clean list.h

CXXFLAGS += -I..

sources = $(wildcard *.cpp)
objects = $(sources:.cpp=.o)

lib$(libname).a: lib$(libname).a($(objects)) $(objects) list.h

map.o: list.h members.h

list.h:
	./genlist $(sources) >$@

members.h: list.h
	./genmembers $^ >$@

clean:
	$(RM) *.o lib$(libname).a list.h members.h
