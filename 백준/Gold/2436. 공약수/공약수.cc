#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a, b;
    cin >> a >> b;

    long long s = a * b;
    long long ansg = LLONG_MAX / 10, ansG = LLONG_MAX / 10;
    for (long long i = a; i * i <= s; i++) {
        if (s % i != 0) {
            continue;
        }
        long long g = gcd(i, s / i);
        long long G = s / g;
        if (g > G) {
            swap(g, G);
        }
        if (!(g == a && G == b)) {
            continue;
        }
        if (ansg + ansG > i + s / i) {
            ansg = min(i, s / i);
            ansG = max(i, s / i);
        }
    }
    cout << ansg << ' ' << ansG;
}