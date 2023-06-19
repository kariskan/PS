#include <iostream>
using namespace std;

int t, n;

bool check(int a[10]) {
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> t;
    while (t--) {
        int a[10] = {0};
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 1) {
                a[i]++;
            }
        }
        int cnt = 0;
        while (!check(a)) {
            int temp[10] = {0};
            for (int i = 0; i < n; i++) {
                temp[(i + 1) % n] = (a[i] + a[(i + 1) % n]) / 2;
            }
            for (int i = 0; i < n; i++) {
                if (temp[i] % 2 == 1) {
                    temp[i]++;
                }
            }
            for (int i = 0; i < n; i++) {
                a[i] = temp[i];
            }
            cnt++;
        }
        cout << cnt << '\n';
    }
}