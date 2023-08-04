#include <iostream>
#include <vector>
using namespace std;

int n, p[48], s[48];
vector<int> info;

bool isExist(vector<int> now) {
    for (int j = 0; j < n; j++) {
        if (info[j] != now[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> now;
    for (int i = 0; i < n; i++) {
        now.push_back(i);
    }
    info = now;
    int t = 0;
    while (1) {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (p[now[i]] != i % 3) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << t;
            break;
        }
        t++;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            v[s[i]] = now[i];
        }

        if (isExist(v)) {
            cout << -1;
            return 0;
        }
        now = v;
    }
}