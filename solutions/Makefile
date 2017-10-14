.PHONY: clean list.h

CXXFLAGS += -I..

sources = $(wildcard *.cpp)
objects = $(sources:.cpp=.o)

lib$(libname).a: $(objects) list.h
	$(AR) $(ARFLAGS) $@ $(objects)

map.o: list.h members.h

list.h:
	./genlist >$@

members.h: list.h
	./genmembers $^ >$@

clean:
	$(RM) *.o lib$(libname).a list.h members.h
