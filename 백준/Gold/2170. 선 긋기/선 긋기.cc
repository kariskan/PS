#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());
    long long ans = 0;
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (v[i].first <= v[idx].second) {
            v[idx].second = max(v[idx].second, v[i].second);
        } else {
            ans += v[idx].second - v[idx].first;
            idx = i;
        }
    }
    ans += v[idx].second - v[idx].first;

    cout << ans;
}