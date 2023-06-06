#include <iostream>
using namespace std;

int a[1001][1001];
int ans[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ans[i] = ans[i] | a[i][j];
            ans[j] = ans[j] | a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}