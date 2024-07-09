#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <mutex>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    // -99 -2 -1 4 98

    int l = 0, r = n - 1;
    int ans=2000000000, ansl = 0, ansr = n - 1;
    while (l < r) {
        int s = v[l] + v[r];

        if (ans > abs(s)) {
            ans = abs(s);
            ansl = v[l];
            ansr = v[r];
        }

        if (s < 0) {
            l++;
        } else {
            r--;
        }
    }

    cout << ansl << ' ' << ansr;
}