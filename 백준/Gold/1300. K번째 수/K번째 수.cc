#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;

    long long left = 1, right = n * n, ans = n * n;
    while (left <= right) {
        long long mid = (left + right) / 2;

        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += min(n, mid / i);
        }

        if (sum >= m) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans;
}