#include <iostream>
using namespace std;

long long n;

int main() {
    cin >> n;

    cout << (long long)((n - 2) * (n - 1) + n - 1) << '\n';

    for (int i = 2; i <= n; i++) {
        cout << "1 " << i << '\n';
    }
}