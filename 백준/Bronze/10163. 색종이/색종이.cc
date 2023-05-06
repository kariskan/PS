#include <iostream>
using namespace std;

int ans[101];
int map[1010][1010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int j = a; j < a + c; j++) {
            for (int k = b; k < b + d; k++) {
                map[j][k] = i + 1;
            }
        }
    }

    for (int i = 0; i < 1010; i++) {
        for (int j = 0; j < 1010; j++) {
            ans[map[i][j]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}