#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

int a[100000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 0, sum = a[0], ans = 0;
    while (r < n) {
        if (sum >= s) {
            if (ans == 0 || ans > r - l + 1) {
                ans = r - l + 1;
            }
            sum -= a[l];
            l++;
        }
        if (r < n && sum < s) {
            r++;
            sum += a[r];
            if (sum >= s) {
                if (ans == 0 || ans > r - l + 1) {
                    ans = r - l + 1;
                }
            }
        }
    }
    while (l <= r) {
        sum -= a[l];
        l++;
        if (sum >= s) {
            if (ans == 0 || ans > r - l + 1) {
                ans = r - l + 1;
            }
        }
    }
    cout << ans;
}