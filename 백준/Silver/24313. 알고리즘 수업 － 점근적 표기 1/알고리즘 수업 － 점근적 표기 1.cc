#include <iostream>
using namespace std;

int main() {
    int a1, a0, c, n0;

    cin >> a1 >> a0 >> c >> n0;

    if (a1 * n0 + a0 > c * n0 || a1 > c || (a1 == c && a0 > 0)) {
        cout << 0;
    } else {
        cout << 1;
    }
}