#include <algorithm>
#include <iostream>
using namespace std;

int p, n, a[1000];

int main() {
    cin >> p >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (p >= 200) {
            break;
        }
        cnt++;
        p += a[i];
    }
    cout << cnt;
}