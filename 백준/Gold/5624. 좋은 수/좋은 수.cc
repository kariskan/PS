#include <iostream>
using namespace std;

int n, a[5000], digit[400001];

int main() {
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            digit[a[i] + a[j] + 200000] = 1;
        }
        for (int j = 0; j <= i; j++) {
            if (digit[a[i + 1] + 100000 - a[j] + 100000]) {
                ans++;
                break;
            }
        }
    }

    cout << ans;
}