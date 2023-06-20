#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long n, ans, a[100001];
vector<long long> v;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long k;
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    int idx = 1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < idx) {
            continue;
        } else if (v[i] == idx) {
            idx++;
        } else {
            ans += abs(idx - v[i]);
            v[i] = idx;
            idx++;
        }
    }
    cout << ans;
}