#include <iostream>
#include <map>
using namespace std;

long long a[200001], s, n, k;
map<long long, long long> d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        
        long long t = s - k * i;

        ans += d[t];
        d[t]++;
    }
    
    ans += d[0];

    cout << ans;
}