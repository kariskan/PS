#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int diff = abs(a - b);
        int remain = n - max(a, b);
        if (a == b) {
            cout << "1\n";
        } else if (a < b) {
            if (diff - remain <= 1) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else {
            if (diff - remain <= 2) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
}