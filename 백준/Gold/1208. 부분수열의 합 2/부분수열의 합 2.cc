#include <iostream>
#include <algorithm>
using namespace std;
long long l[1050000], r[1050000];
int a[20], b[20];
int main() {
    int n, m;
    cin >> n >> m;
    int idx = 0, idx2 = 0;
    for (int i = 0; i < n; i++) {
        if (i >= n / 2) {
            cin >> b[idx++];
        }
        else cin >> a[i];
    }
    idx = 0;
    for (int i = 0; i < (1 << (n / 2)); i++) {
        long long sum = 0;
        for (int j = 0; j < n / 2; j++) {
            if (i & (1 << j)) {
                sum += a[j];
            }
        }
        l[idx++] = sum;
    }
    sort(l, l + idx);
    for (int i = 0; i < (1 << (n + 1) / 2); i++) {
        long long sum = 0;
        for (int j = 0; j < (n + 1) / 2; j++) {
            if (i & (1 << j)) {
                sum += b[j];
            }
        }
        r[idx2++] = sum;
    }
    sort(r, r + idx2);
    int p1 = 0; int p2 = idx2 - 1;
    long long ans = 0;
    while (p1 < idx && p2 >= 0) {
        if (l[p1] + r[p2] == m) {
            long long lCount = 1;
            long long rCount = 1;
            p1++;
            p2--;
            while (p1 < idx && l[p1] == l[p1 -1]) {
                p1++;
                lCount++;
            }
            while (p2 >= 0 && r[p2] == r[p2 + 1]) {
                p2--;
                rCount++;
            }
            ans += lCount * rCount;
        }
        else if (l[p1] + r[p2] > m) {
            p2--;
        }
        else {
            p1++;
        }
    }
    if (m == 0)ans--;
    cout << ans;
}