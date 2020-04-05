#include "min_dist.h"

long long pow2(long long x) {
    return x * x;
}

std::istream& operator>>(std::istream &in, point &p) {
    in >> p.first >> p.second;
    return in;
}

long long min_distance_impl(std::vector<point>::const_iterator l, std::vector<point>::const_iterator r, std::vector<point> &result) {
    if (r - l == 1) {
        result.push_back(*l);
        return std::numeric_limits<long long>::max();
    }
    auto m = l + (r - l) / 2;
    const point &middle = *m;

    std::vector<point> left, right;
    long long min_dist = std::min(min_distance_impl(l, m, left), min_distance_impl(m, r, right));

    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(result),
               [](auto &a, auto &b) {return a.second < b.second;});

    std::vector<point> strip;
    std::copy_if(result.begin(), result.end(), std::back_inserter(strip),
                 [=](point &p) {return pow2(p.first - middle.first) < min_dist;});

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i+1; j < strip.size() && pow2(strip[j].second - strip[i].second) < min_dist; j++) {
            min_dist = std::min(min_dist, get_distance(strip[i], strip[j]));
        }
    }
    return min_dist;
}

long long get_distance(const point &a, const point &b) {
    return pow2(a.first - b.first) + pow2(a.second - b.second);
}

long long min_distance(const std::vector<point> &xs) {
    std::vector<point> result;
    std::vector<point> sorted_xs(xs);
    std::sort(sorted_xs.begin(), sorted_xs.end());
    return min_distance_impl(sorted_xs.begin(), sorted_xs.end(), result);
}