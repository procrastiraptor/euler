cargs = -O3
bindir = bin
gnatargs = -gnatwa -gnatwe -D $(bindir)

solutions = $(wildcard euler*.adb)

.PHONY: clean

all: $(basename $(solutions))

.DEFAULT:
	gnatmake $(gnatargs) $@ -cargs $(cargs)

clean:
	$(RM) $(bindir)/*
	find . -type f -executable -delete
