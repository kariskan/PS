#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    while (v.size() > 1) {
        v[0]--;
        v[v.size() - 2] += v[v.size() - 1];
        v.pop_back();
        ans++;
        if (!v[0]) {
            for (int i = 0; i < v.size() - 1; i++) {
                v[i] = v[i + 1];
            }
            v.pop_back();
        }
    }
    cout << ans;
}