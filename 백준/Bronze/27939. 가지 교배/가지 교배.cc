#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[1000] = {0};
    for (int i = 0; i < n; i++) {
        char b;
        cin >> b;
        if (b == 'W') {
            a[i] = 1;
        } else {
            a[i] = 2;
        }
    }

    int m, k;
    cin >> m >> k;
    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (int j = 0; j < k; j++) {
            int c;
            cin >> c;
            if (a[c - 1] == 2) {
                flag = false;
            }
        }
        if (flag) {
            cout << "W";
            return 0;
        }
    }
    cout << "P";
}