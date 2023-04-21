#include <iostream>
using namespace std;

int fib[41] = {0, 1, 1};

int main() {
    int n;
    cin >> n;

    for (int i = 3; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << fib[n] << ' ';

    if (n == 1 || n == 2) {
        cout << 1;
    } else {
        cout << n - 2;
    }
}