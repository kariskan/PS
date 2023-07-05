#include <iostream>
#include <vector>
using namespace std;

int t;
string s[1000];

void rotate(int idx, int clockwise) {
    string t = s[idx];
    if (clockwise == 1) {
        char pre = s[idx][0];
        for (int i = 1; i < 8; i++) {
            char temp = s[idx][i];
            s[idx][i] = pre;
            pre = temp;
        }
        s[idx][0] = pre;
    } else {
        char pre = s[idx][7];
        for (int i = 6; i >= 0; i--) {
            char temp = s[idx][i];
            s[idx][i] = pre;
            pre = temp;
        }
        s[idx][7] = pre;
    }
}

// 1일때 시계, -1일때 반시계
void go(int num, int clockwise) {
    vector<pair<int, int>> will;
    will.push_back({num, clockwise});
    int cnt = -1;
    for (int i = num - 1; i >= 0; i--) {
        if (s[i][2] != s[i + 1][6]) {
            will.push_back({i, clockwise * cnt});
            cnt *= -1;
        } else
            break;
    }
    cnt = -1;
    for (int i = num + 1; i < t; i++) {
        if (s[i][6] != s[i - 1][2]) {
            will.push_back({i, clockwise * cnt});
            cnt *= -1;
        } else
            break;
    }

    for (int i = 0; i < will.size(); i++) {
        rotate(will[i].first, will[i].second);
    }
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num, clockwise;
        cin >> num >> clockwise;
        go(num - 1, clockwise);
    }
    int ans = 0;
    for (int i = 0; i < t; i++) {
        if (s[i][0] == '1') {
            ans++;
        }
    }
    cout << ans;
}