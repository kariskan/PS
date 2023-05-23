#include <iostream>
#include <map>
using namespace std;

map<int, long long> ma;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ma[0] = -1;
    ma[300001] = -1;
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        long long cnt = 0;
        auto j = ma.upper_bound(a);
        auto k = j--;
        cnt = max(j->second, k->second) + 1;
        ma[a] = cnt;
        ans += cnt;
        cout << ans << '\n';
    }
}