#include <iostream>
using namespace std;

int a[10000];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ans++;
                if (ans == m) {
                    for (int k = 0; k < n; k++) {
                        cout << a[k] << ' ';
                    }
                    cout<<'\n';
                    return 0;
                }
            }
        }
    }
    cout << -1;
}