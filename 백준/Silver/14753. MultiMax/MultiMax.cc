#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int ans = a[n - 1] * a[n - 2] * a[n - 3];
    ans = max(ans, a[n - 1] * a[0] * a[1]);
    ans = max(ans, a[n - 1] * a[n - 2]);
    ans = max(ans, a[0] * a[1]);
    
    cout << ans;
}