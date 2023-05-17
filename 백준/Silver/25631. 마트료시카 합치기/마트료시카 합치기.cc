#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
int vis[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    int ans = 0;

    for (int i = 0; i < v.size(); i++) {
        if (vis[i]) {
            continue;
        }
        ans++;
        int last = v[i];
        for (int j = i; j < v.size(); j++) {
            if (!vis[j] && v[j] > last) {
                vis[j] = 1;
                last = v[j];
            }
        }
    }

    cout << ans;
}