#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int ans = 0;
    while (v.size() != 1) {
        int mi = 0, idx = 0;
        for (int i = 0; i < v.size(); i++) {
            if (mi < v[i]) {
                mi = v[i];
                idx = i;
            }
        }

        if (idx == 0) {
            ans += abs(v[0] - v[1]);
            v[0] = min(v[0], v[1]);
            v.erase(v.begin() + 1);
        } else if (idx == v.size() - 1) {
            ans += abs(v[idx] - v[idx - 1]);
            v[idx - 1] = min(v[idx], v[idx - 1]);
            v.erase(v.begin() + idx);
        } else {
            if (abs(v[idx] - v[idx - 1]) > abs(v[idx] - v[idx + 1])) {
                ans += abs(v[idx] - v[idx + 1]);
                v[idx] = min(v[idx], v[idx + 1]);
                v.erase(v.begin() + idx + 1);
            } else {
                ans += abs(v[idx] - v[idx - 1]);
                v[idx] = min(v[idx], v[idx - 1]);
                v.erase(v.begin() + idx - 1);
            }
        }
    }
    cout << ans;
}