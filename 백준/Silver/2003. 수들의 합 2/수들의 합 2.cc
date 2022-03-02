#include <iostream>
using namespace std;
int a[10000];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p1 = 0, p2 = 0;
    int sum = a[0];
    int ans = 0;
    while (p1 <= p2 && p2 < n) {
        if (sum > m) {
            sum -= a[p1];
            p1++;
            if (p1<n && p1>p2) {
                p2 = p1;
                sum = a[p2];
            }
        }
        else if (sum < m) {
            p2++;
            sum += a[p2];
        }
        else {
            ans++;
            p2++;
            sum += a[p2];
        }
    }
    cout << ans;
}