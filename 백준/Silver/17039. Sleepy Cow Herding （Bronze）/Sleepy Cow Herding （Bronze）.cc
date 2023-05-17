#include <algorithm>
#include <iostream>
using namespace std;

int a[3];

int main() {
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);

    if (a[1] - a[0] == 1 && a[2] - a[1] == 1) {
        cout << 0;
    } else if (a[1] - a[0] == 2 || a[2] - a[1] == 2) {
        cout << 1;
    } else {
        cout << 2;
    }
    cout << '\n';
    cout << max(a[1] - a[0], a[2] - a[1]) - 1;
}