#include <iostream>
using namespace std;

int n, x, y;

int main() {
    cin >> n >> x >> y;

    if (n == 1) {
        cout << 0;
    } else {
        if ((x == 1 && y == 1) || (x == 1 && y == n) || (x == n && y == 1) ||
            (x == n && y == n)) {
            cout << 2;
        } else if (x == 1 || y == 1 || x == n || y == n) {
            cout << 3;
        } else {
            cout << 4;
        }
    }
}