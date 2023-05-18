#include <iostream>
using namespace std;

int n, m;
int a[10000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        int maxElement = 0, idx;
        for (int j = 0; j <= i; j++) {
            if (maxElement < a[j]) {
                maxElement = a[j];
                idx = j;
            }
        }
        if (idx != i) {
            m--;
            swap(a[i], a[idx]);
            if (m == 0) {
                for (int k = 0; k < n; k++) {
                    cout << a[k] << ' ';
                }
                return 0;
            }
        }
    }
    cout << -1;
}