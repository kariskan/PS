#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int n, m;
pair<int, int> a[100001];

bool compare(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second) {
        return p1.first > p2.first;
    }
    return p1.second < p2.second;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n, compare);
    int ans = -1;
    int before = -1, weightSum = 0, priceSum = 0;
    for (int i = 1; i <= n; i++) {
        weightSum += a[i].first;

        if (a[i].second == a[i - 1].second) {
            priceSum += a[i].second;
        } else {
            priceSum = 0;
        }
        if (weightSum >= m) {
            if (ans == -1 || ans > a[i].second + priceSum) {
                ans = a[i].second + priceSum;
            }
        }
    }

    cout << ans;
}