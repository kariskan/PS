#include <iostream>
using namespace std;

int a[100000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            cnt++;
        }
    }
    if (cnt >= 2) {
        cout << 0;
    } else if (cnt == 0) {
        cout << n;
    } else {
        int idx;
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                idx = i;
                break;
            }
        }
        if (idx == n - 1 || (idx < n - 1 && a[idx - 1] <= a[idx + 1])){
            cnt++;
        }
        if (idx <= 1 || (idx > 1 && a[idx - 2] <= a[idx])) {
            cnt++;
        }
        cout << cnt;
    }
}