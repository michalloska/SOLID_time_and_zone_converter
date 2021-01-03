#pragma once
#include <utility>
#include <ostream>

using Time = std::pair<int,int>;

std::ostream& operator<<(std::ostream & out, const Time & time);
