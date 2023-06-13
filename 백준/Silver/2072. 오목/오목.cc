#include <iostream>
using namespace std;

int n, map[20][20];

bool check(int i, int j) {
    int up = i, down = i;

    while (up > 0 && map[up][j] == map[i][j]) {
        up--;
    }
    while (down <= 19 && map[down][j] == map[i][j]) {
        down++;
    }
    if (down - up - 1 == 5) {
        return true;
    }

    int left = j, right = j;

    while (left > 0 && map[i][left] == map[i][j]) {
        left--;
    }
    while (right <= 19 && map[i][right] == map[i][j]) {
        right++;
    }
    if (right - left - 1 == 5) {
        return true;
    }

    up = i, down = i, left = j, right = j;
    while (up > 0 && right <= 19 && map[up][right] == map[i][j]) {
        up--;
        right++;
    }
    while (down <= 19 && left > 0 && map[down][left] == map[i][j]) {
        down++;
        left--;
    }
    if (down - up - 1 == 5) {
        return true;
    }
    
    up = i, down = i, left = j, right = j;
    while (up > 0 && left > 0 && map[up][left] == map[i][j]) {
        up--;
        left--;
    }
    while (down <= 19 && right <= 19 && map[down][right] == map[i][j]) {
        down++;
        right++;
    }
    if (down - up - 1 == 5) {
        return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = i % 2 + 1;
        if (check(a, b)) {
            cout << i + 1;
            return 0;
        }
    }
    cout << -1;
}