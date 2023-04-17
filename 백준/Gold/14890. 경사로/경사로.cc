#include <iostream>
using namespace std;

int map[100][100];
int n, l;

bool rowCheck(int i) {
    int check[100] = {
        0,
    };
    for (int j = 1; j < n; j++) {
        if (map[i][j] == map[i][j - 1]) {
            continue;
        }
        int cnt = 0, idx;
        if (map[i][j] == map[i][j - 1] + 1) {
            idx = j - 1;
            while (idx >= 0 && map[i][j - 1] == map[i][idx] && cnt < l && !check[idx]) {
                check[idx] = 1;
                idx--;
                cnt++;
            }
        } else if (map[i][j] + 1 == map[i][j - 1]) {
            idx = j;
            while (idx < n && map[i][j] == map[i][idx] && cnt < l && !check[idx]) {
                check[idx] = 1;
                idx++;
                cnt++;
            }
            j = idx - 1;
        }
        if (cnt < l) {
            return false;
        }
    }

    return true;
}

bool colCheck(int j) {
    int check[100] = {
        0,
    };
    for (int i = 1; i < n; i++) {
        if (map[i][j] == map[i - 1][j]) {
            continue;
        }
        int cnt = 0, idx;
        if (map[i][j] == map[i - 1][j] + 1) {
            idx = i - 1;
            while (idx >= 0 && map[i - 1][j] == map[idx][j] && cnt < l && !check[idx]) {
                check[idx] = 1;
                idx--;
                cnt++;
            }
        } else if (map[i][j] + 1 == map[i - 1][j]) {
            idx = i;
            while (idx < n && map[i][j] == map[idx][j] && cnt < l && !check[idx]) {
                check[idx] = 1;
                idx++;
                cnt++;
            }
            i = idx - 1;
        }
        if (cnt < l) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (rowCheck(i)) {
            ans++;
        }
        if (colCheck(i)) {
            ans++;
        }
    }

    cout << ans;
}