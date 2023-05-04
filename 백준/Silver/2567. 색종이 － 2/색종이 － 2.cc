#include <iostream>
using namespace std;

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
int map[101][101], n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < a + 10; j++) {
            for (int k = b; k < b + 10; k++) {
                map[j][k] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (map[i][j]) {
                int flag = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + x[k];
                    int ny = j + y[k];
                    if (nx >= 0 && nx <= 100 & ny >= 0 && ny <= 100 && !map[nx][ny]) {
                        flag++;
                    }
                }
                ans += flag;
            }
        }
    }

    cout << ans;
}