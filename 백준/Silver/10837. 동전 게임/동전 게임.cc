#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "1\n";
        } else if (a < b) {
            if (n - max(a, b) >= abs(b - a) - 1) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else {
            if (n - max(a, b) >= abs(b - a) - 2) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
}