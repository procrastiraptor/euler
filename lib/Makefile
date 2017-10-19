.PHONY: clean

sources = $(wildcard *.cpp)
objects = $(sources:.cpp=.o)

libutil.a: $(objects)
	$(AR) $(ARFLAGS) $@ $?

clean:
	$(RM) *.a *.o
