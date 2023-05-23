#include <iostream>
using namespace std;

char map[102][102];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    int starti, startj, width, height;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '#') {
                starti = i;
                startj = j;
                int idx = n - 1;
                while (map[idx][j] != '#') {
                    idx--;
                }
                height = idx - i + 1;

                idx = m - 1;
                while (map[i][idx] != '#') {
                    idx--;
                }
                width = idx - j + 1;
                
                for (int k = startj + 1; k < startj + width - 1; k++) {
                    if (map[starti][k] == '.') {
                        cout << "UP";
                        return 0;
                    }
                }
                for (int k = startj + 1; k < startj + width - 1; k++) {
                    if (map[starti + height - 1][k] == '.') {
                        cout << "DOWN";
                        return 0;
                    }
                }
                for (int k = starti + 1; k < starti + height - 1; k++) {
                    if (map[k][startj] == '.') {
                        cout << "LEFT";
                        return 0;
                    }
                }
                for (int k = starti + 1; k < starti + height - 1; k++) {
                    if (map[k][startj + width - 1] == '.') {
                        cout << "RIGHT";
                        return 0;
                    }
                }
            }
        }
    }
}