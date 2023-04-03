#include <iostream>
#include <map>
using namespace std;

map<int, int> ma, ma2;
int n, m, k;

// -1일 경우, 둘 다 조건을 만족하지 못함
// -2일 경우, 조건을 만족하는 키가 2개
int findKey(int key) {
    auto it = ma.lower_bound(key);
    auto it2 = ma2.lower_bound(-key);

    if (it == ma.end() && it2 == ma2.end()) {
        return -1;
    } else if (it == ma.end()) {
        if (abs(-(it2->first) - key) > k) {
            return -1;
        }
        return (-it2->first);
    } else if (it2 == ma2.end()) {
        if (abs(it->first - key) > k) {
            return -1;
        }
        return it->first;
    }

    int v1 = abs(it->first - key);
    int v2 = abs(-(it2->first) - key);

    if (v1 > k && v2 > k) {
        return -1;
    }
    if (it->first == -(it2->first)) {
        return it->first;
    }
    if (v1 == v2) {
        return -2;
    }
    if (v1 > v2) {
        return -(it2->first);
    }
    return it->first;
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ma[a] = b;
        ma2[-a] = b;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a;
        if (a == 3) {
            cin >> b;
            int key = findKey(b);

            if (key == -2) {
                cout << "?";
            } else if (key == -1) {
                cout << -1;
            } else
                cout << ma[key];
            cout << '\n';
        } else {
            cin >> b >> c;
            if (a == 1) {
                ma[b] = c;
                ma2[-b] = c;
            } else {
                int key = findKey(b);

                if (key == -1 || key == -2) {
                    continue;
                }
                if (ma.find(key) == ma.end()) {
                    continue;
                }
                ma[key] = c;
                ma2[-key] = c;
            }
        }
    }
}