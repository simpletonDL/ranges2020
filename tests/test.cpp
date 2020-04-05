#include <iostream>
#include "../src/min_dist.h"

std::ostream& operator<<(std::ostream &out, point const &p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
std::ostream& operator<<(std::ostream &out, std::vector<T> const &p) {
    out << "{";
    for (const auto &x: p) {
        out << x << " ";
    }
    out << "}";
    return out;
}

long long brute_force(std::vector<point> xs) {
    long long min_dist = std::numeric_limits<long long>::max();
    for (int i = 0; i < xs.size(); ++i) {
        for (int j = 0; j < xs.size(); ++j) {
            if (i != j) {
                min_dist = std::min(min_dist, get_distance(xs[i], xs[j]));
            }
        }
    }
    return min_dist;
}
//
std::vector<point> gen(int n, int k) {
    std::vector<point> xs;
    for (int i = 0; i < n; ++i) {
        xs.push_back({rand() % k, rand() % k});
    }
    return xs;
}

int test(int count, int arr_len, int max_cord) {
    srand(time(0));
    for (int i = 0; i < count; ++i) {
        std::cout << "TEST " << i << ") ";
        std::vector<point> xs = gen(arr_len, max_cord);
        long long res = min_distance(xs);
        long long requiered = brute_force(xs);
        if (res == requiered) {
            std::cout << "OK:" << res << " == " << requiered << "\n";
        } else {
            std::cerr << "FAIL: " << res << " != " << requiered << "\n";
            std::cerr << "xs = " << xs << "\n";
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int main(const int argc, const char *argv[]) {
    if (argc != 4) {
        std::cerr << "Expected 3 arguments";
        return EXIT_FAILURE;
    }
    return test(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
}