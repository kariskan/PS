#include <iostream>

using namespace std;

int n, a[20], s[2000002];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    s[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 2000001 - a[i]; j >= 0; j--) {
            if (s[j]) {
                s[j + a[i]] = 1;
            }
        }
    }
    for (int i = 1; i <= 2000001; i++) {
        if (!s[i]) {
            cout << i;
            return 0;
        }
    }
}