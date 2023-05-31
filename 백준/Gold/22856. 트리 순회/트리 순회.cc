#include <iostream>
using namespace std;

pair<int, int> a[100001];
int p[100001], ans, vis[100001], cnt, n;
int last;

void inOrder(int node) {
    if (a[node].first != -1) {
        inOrder(a[node].first);
    }
    last = node;
    if (a[node].second != -1) {
        inOrder(a[node].second);
    }
}

void go(int node, int pre) {
    if (a[node].first != -1 && !vis[a[node].first]) {
        ans++;
        vis[a[node].first] = 1;
        go(a[node].first, node);
    }
    if (a[node].second != -1 && !vis[a[node].second]) {
        ans++;
        vis[a[node].second] = 1;
        go(a[node].second, node);
    }
    if (node == last) {
        cout << ans;
        exit(0);
    }
    if (p[node] != 0) {
        ans++;
        if (!vis[p[node]]) {
            vis[p[node]] = 1;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int parent, c1, c2;
        cin >> parent >> c1 >> c2;
        a[parent] = {c1, c2};
        if (c1 != -1) {
            p[c1] = parent;
        }
        if (c2 != -1) {
            p[c2] = parent;
        }
    }
    inOrder(1);
    go(1, 0);
    cout << ans;
}