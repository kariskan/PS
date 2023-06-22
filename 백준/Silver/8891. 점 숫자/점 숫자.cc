#include <iostream>
using namespace std;

pair<int, int> get(int n) {
    int x = 0, y = 1, cnt = 0;

    while (n != cnt) {
        x++;
        y--;
        cnt++;
        if (y == 0) {
            y = x;
            x = 1;
        }
    }

    return {x, y};
}

int get2(pair<int, int> p) {
    int x = 1, y = 1, cnt = 1;
    while (!(p.first == x && p.second == y)) {
        cnt++;
        x++;
        y--;
        if (y == 0) {
            y = x;
            x = 1;
        }
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        pair<int, int> p1 = get(n);
        pair<int, int> p2 = get(m);

        cout << get2({p1.first + p2.first, p1.second + p2.second}) << '\n';
    }
}