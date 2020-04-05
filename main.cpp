#include <cmath>
#include "src/min_dist.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<point> xs(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
    }

    cout << sqrt(min_distance(xs));
    return 0;
}