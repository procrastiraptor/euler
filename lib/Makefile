.PHONY: clean

sources = $(wildcard *.cpp)
objects = $(sources:.cpp=.o)

libutil.a: $(objects)
	$(AR) $(ARFLAGS) $@ $(objects)

clean:
	$(RM) *.a *.o
