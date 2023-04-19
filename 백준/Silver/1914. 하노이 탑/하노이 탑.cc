#include <cmath>
#include <iostream>
using namespace std;

void go(int n, int a, int b, int c) {
    if (n == 1) {
        cout << a << ' ' << c << '\n';
        return;
    }
    go(n - 1, a, c, b);
    cout << a << ' ' << c << '\n';
    go(n - 1, b, a, c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string a = to_string(pow(2, n));
    a = a.substr(0, a.find('.'));
    a[a.length() - 1] -= 1;

    cout << a << '\n';
    if (n <= 20) {
        go(n, 1, 2, 3);
    }
}