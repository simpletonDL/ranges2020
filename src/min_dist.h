#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

using point = std::pair<int, int>;

std::istream& operator>>(std::istream &in, point &p);

long long get_distance(const point &a, const point &b);
long long min_distance(const std::vector<point> &xs);