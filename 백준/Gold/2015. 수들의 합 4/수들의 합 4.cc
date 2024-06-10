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

int a[200001], s[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    map<int, long long> ma;
    long long ans = 0;
    ma[0]++;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        if (ma.find(s[i] - k) != ma.end()) {
            ans += ma[s[i] - k];
        }
        ma[s[i]]++;
    }
    cout << ans;
}