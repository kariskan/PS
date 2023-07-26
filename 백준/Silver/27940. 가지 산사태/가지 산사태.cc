#include <iostream>
using namespace std;

int n, m, k;

int main() {
    cin >> n >> m >> k;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        sum += b;
        if (sum > k) {
            cout << i + 1 << ' ' << 1;
            return 0;
        }
    }
    cout << -1;
}