#include <algorithm>
#include <iostream>
using namespace std;
int n, k, a[1010], ans;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int left = 0, right = 0;

    while (right < n) {
        ans = max(ans, right - left + 1);

        right++;
        while (abs(a[left] - a[right]) > k) {
            left++;
        }
    }

    cout << ans;
}