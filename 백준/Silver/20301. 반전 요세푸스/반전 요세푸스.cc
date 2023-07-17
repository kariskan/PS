#include <iostream>
using namespace std;

int n, k, m, vis[5001];

int main() {
    cin >> n >> k >> m;
    cout << k;
    int now = k;
    vis[now] = 1;
    int cnt = 1, rot = 0;
    while (cnt < n) {
        if (cnt % m == 0) {
            rot = 1 - rot;
        }
        int q = k;
        while (q != 0) {
            if (rot == 0) {
                now++;
                if (now > n) {
                    now = 1;
                }
            } else {
                now--;
                if (now == 0) {
                    now = n;
                }
            }
            if (!vis[now]) {
                q--;
            }
        }
        vis[now] = 1;
        cnt++;
        cout << " " << now;
    }
}