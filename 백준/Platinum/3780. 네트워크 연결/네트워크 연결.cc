#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int t, n, p[20001], line[20001], ans;

int Find(int x) {
    if (p[x] == x) {
        return x;
    }
    int k = Find(p[x]);
    line[x] += line[p[x]];
    return p[x] = k;
}

void Union(int a, int b) {
    if (a != b) {
        p[a] = b;
        line[a] = abs(a - b) % 1000;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n;
        memset(line, 0, sizeof(line));
        for (int i = 1; i <= n; i++) {
            p[i] = i;
        }
        while (1) {
            char a;
            int b, c;
            cin >> a;
            if (a == 'O') {
                break;
            }
            if (a == 'E') {
                cin >> b;
            } else {
                cin >> b >> c;
            }

            if (a == 'E') {
                Find(b);
                cout << line[b] << '\n';
            } else {
                Union(b, c);
            }
        }
    }
}