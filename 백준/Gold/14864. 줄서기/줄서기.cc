#include <iostream>
using namespace std;

int num[100001], in[100001], out[100001], ans[100001];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        out[a]++;
        in[b]++;
    }

    for (int i = 1; i <= n; i++) {
        int less = out[i] + i - 1 - in[i];
        int greater = n - i - out[i] + in[i];
        if (less + greater >= n || num[less + 1]) {
            cout << -1;
            return 0;
        }
        num[less + 1] = 1;
        ans[i] = less + 1;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}