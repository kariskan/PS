#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << 1 << '\n';
        cout << "(0,0)\n";
        for (int i = 0; i < n; i++) {
            for (int j = i % 2 ? m - 1 : 1; i % 2 ? j > 0 : j < m;
                 i % 2 ? j-- : j++) {
                cout << "(" << i << "," << j << ")\n";
            }
        }
        for (int i = n - 1; i > 0; i--) {
            cout << "(" << i << ",0)\n";
        }
    }
}