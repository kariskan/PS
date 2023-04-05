#include <algorithm>
#include <iostream>
using namespace std;

long long n, t;
pair<long long, long long> inp[200000];

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> inp[i].second >> inp[i].first;
    }

    sort(inp, inp + n);

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += inp[i].first * (t - n + i) + inp[i].second;
    }

    cout << ans;
}