#include <cstring>
#include <iostream>
using namespace std;

char map[500][500];

int main() {
    int n;
    cin >> n;
    memset(map, ' ', sizeof(map));
    int idx = 0, flag = 0, idx2 = 0, flag2 = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        map[i][idx] = map[i][idx + n - 1] = map[i][3 * n - 3 + idx2] = map[i][4 * n - 4 + idx2] = '*';

        if (i == n - 1) {
            flag = 1;
        }
        if (i == n - 1) {
            flag2 = 1;
        }
        if (!flag) {
            idx++;
        } else {
            idx--;
        }
        if (!flag2) {
            idx2--;
        } else {
            idx2++;
        }
    }
    for (int i = 0; i < n; i++) {
        map[0][i] = map[2 * n - 2][i] = map[0][3 * n - 3 + i] = map[2 * n - 2][3 * n - 3 + i] = '*';
    }
    idx2 = 0, flag2 = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j <= 4 * n - 4 + idx2; j++) {
            cout << map[i][j];
        }
        if (i == n - 1) {
            flag2 = 1;
        }
        if (!flag2) {
            idx2--;
        } else {
            idx2++;
        }
        cout << '\n';
    }
}