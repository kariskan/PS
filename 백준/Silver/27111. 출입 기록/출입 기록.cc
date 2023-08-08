#include <iostream>
using namespace std;

int n, a[200001];

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        if (p2 == 1) {
            if (a[p1]) {
                ans++;
            }
            a[p1] = 1;
        } else {
            if (!a[p1]) {
                ans++;
            }
            a[p1] = 0;
        }
    }
    for (int i = 1; i <= 200000; i++) {
        if (a[i]) {
            ans++;
        }
    }
    cout << ans;
}