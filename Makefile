export CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -O3

solution_dir = solutions
solution_lib = solve
LDFLAGS = -L$(solution_dir)
LDLIBS = -l$(solution_lib)

.PHONY: clean $(solution_dir)

euler: $(solution_dir)
	$(MAKE) -C $(solution_dir) libname=$(solution_lib)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $@.cpp $(LDLIBS) -o $@

clean:
	$(MAKE) -C $(solution_dir) libname=$(solution_lib) clean
	$(RM) euler
