#pragma once

#include <functional>
#include <map>

using Solution = std::function<long()>;

extern std::map<int, Solution> solutions;
