#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        double t;
        cin >> t;
        long long p = 10;
        while (1) {
            if (t >= p) {
                t = round(t / p);
                t *= p;
            } else {
                cout << (long long)t << '\n';
                break;
            }
            p *= 10;
        }
    }
}