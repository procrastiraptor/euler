export CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -O3
export ARFLAGS = r

util_dir = lib
solution_dir = solutions
solution_lib = solve
LDFLAGS = -L$(solution_dir) -L$(util_dir)
LDLIBS = -l$(solution_lib) -lprimes -lgmp -lgmpxx

.PHONY: clean $(solution_dir)

euler: $(solution_dir)
	$(MAKE) -C $(util_dir)
	$(MAKE) -C $(solution_dir) libname=$(solution_lib)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $@.cpp $(LDLIBS) -o $@

clean:
	$(MAKE) -C $(util_dir) clean
	$(MAKE) -C $(solution_dir) libname=$(solution_lib) clean
	$(RM) euler
