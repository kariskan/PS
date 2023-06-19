#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<long long> v;
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        for (int j = 0; j < c; j++) {
            v.push_back(a + b * j);
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= t) {
            cout << v[i] - t;
            return 0;
        }
    }
    cout << -1;
}