#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
        vector<long long> v, vis(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            long long a;
            cin >> a;
            v.push_back(a);
        }
        cout << "Case #" << tc << ": ";
        for (int i = 0; i < 2 * n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                for (int j = i + 1; j < 2 * n; j++) {
                    if ((v[j] * 3) / 4 == v[i] && !vis[j]) {
                        vis[j] = 1;
                        cout << v[i] << ' ';
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }
}