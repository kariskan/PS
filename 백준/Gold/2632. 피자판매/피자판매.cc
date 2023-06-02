#include <iostream>
using namespace std;

int k, n, m, a[1000], b[1000];
int pa[2000001], pb[2000001];

int main() {
    cin >> k >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }
    int atotal = 0;
    for (int i = 0; i < n; i++) {
        atotal += a[i];
        int temp = 0;
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
            temp += a[j];
            pa[temp]++;
        }
    }
    pa[atotal]++;

    int btotal = 0;
    for (int i = 0; i < m; i++) {
        btotal += b[i];
        int temp = 0;
        for (int j = (i + 1) % m; j != i; j = (j + 1) % m) {
            temp += b[j];
            pb[temp]++;
        }
    }
    pb[btotal]++;

    int ans = 0;
    for (int i = 1; i < k; i++) {
        ans += pa[i] * pb[k - i];
    }
    ans += pa[k] + pb[k];
    
    cout << ans;

    return 0;
}