#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long d, n;
        cin >> d >> n;
        vector<long long> v(n);
        map<long long, long long> m;
        int ans = 0;
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (i > 0) {
                v[i] += v[i - 1];
            }
            if (m.find(v[i] % d) != m.end()) {
                ans += m[v[i] % d];
            }
            m[v[i] % d]++;
        }
        cout << ans << '\n';
    }
}
