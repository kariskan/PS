#include <iostream>
using namespace std;

int n, a[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        while (a[i] == a[idx]) {
            idx++;
        }
        if (idx > n) {
            cout << "-1 ";
        } else {
            cout << idx << ' ';
        }
    }
}