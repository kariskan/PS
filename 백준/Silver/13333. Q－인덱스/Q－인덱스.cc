#include <algorithm>
#include <iostream>
using namespace std;

int n, a[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = n; i >= 0; i--) {
        if (a[n - i] >= i) {
            cout << i;
            break;
        }
    }
}