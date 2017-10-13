#pragma once

#include <functional>
#include <map>

using Solution = std::function<int()>;

extern std::map<int, Solution> solutions;
