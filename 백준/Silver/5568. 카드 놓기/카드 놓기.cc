#include <iostream>
#include <set>

using namespace std;

int n, k, vis[10], a[10];
set<string> se;

void go(int cnt, string now) {
    if (cnt == k) {
        se.insert(now);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            go(cnt + 1, now + to_string(a[i]));
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    go(0, "");
    cout << se.size();
}