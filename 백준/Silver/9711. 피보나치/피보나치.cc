#include <iostream>
using namespace std;

int t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        long long n, m;
        cin >> n >> m;
        long long fib[10001] = {0};
        fib[1] = fib[2] = 1;
        for (int j = 3; j <= n; j++) {
            fib[j] = (fib[j - 1] + fib[j - 2]) % m;
        }
        cout << "Case #" << i << ": " << fib[n] % m << '\n';
    }
}