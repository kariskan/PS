#include <cstring>
#include <iostream>
using namespace std;

int n, a[2][5];

int main() {
    cin >> n;
    while (n--) {
        memset(a, 0, sizeof(a));
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            a[0][k]++;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            a[1][k]++;
        }
        bool flag = false;
        for (int i = 4; i >= 1; i--) {
            if (a[0][i] > a[1][i]) {
                cout << "A";
                flag = true;
                break;
            } else if (a[0][i] < a[1][i]) {
                cout << "B";
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "D";
        }
        cout << '\n';
    }
}