#include <iostream>
using namespace std;
int a[1000][5], cnt[1000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0, idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = 0; k < 5; k++) {
                if (a[i][k] == a[j][k]) {
                    cnt[i]++;
                    break;
                }
            }
        }
        if (ans < cnt[i]) {
            ans = cnt[i];
            idx = i;
        }
    }
    cout << idx + 1;
}