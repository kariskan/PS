#include <algorithm>
#include <iostream>
using namespace std;
int a[50];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 5;

    for (int i = 0; i < n; i++) {
        int idx = i;
        while (1) {
            if (idx + 1 >= n || a[idx + 1] > a[i] + 4) {
                break;
            }
            idx++;
        }
        ans = min(ans, 5 - (idx - i + 1));
    }
    cout << ans;
}