#include <iostream>
using namespace std;

long long d, x, y, i, j;
string s;

void go(string s, long long lx, long long ly, long long rx, long long ry) {
    if (!(i >= lx && i <= rx && j >= ly && j <= ry)) {
        return;
    }
    if (lx == rx && ly == ry) {
        cout << s;
        exit(0);
    }
    go(s + "2", lx, ly, (lx + rx) / 2, (ly + ry) / 2);
    go(s + "1", lx, (ly + ry + 1) / 2, (lx + rx) / 2, ry);
    go(s + "3", (lx + rx + 1) / 2, ly, rx, (ly + ry) / 2);
    go(s + "4", (lx + rx + 1) / 2, (ly + ry + 1) / 2, rx, ry);
}

int main() {
    cin >> d >> s >> x >> y;

    long long lx = 1, ly = 1, rx = 1LL << s.length(), ry = 1LL << s.length();
    for (int i = 0; i < s.length(); i++) {
        int quad = s[i] - '0';
        if (quad == 2) {
            rx = (lx + rx) / 2;
            ry = (ly + ry) / 2;
        } else if (quad == 1) {
            ly = (ly + ry + 1) / 2;
            rx = (lx + rx) / 2;
        } else if (quad == 3) {
            lx = (lx + rx + 1) / 2;
            ry = (ly + ry) / 2;
        } else {
            lx = (lx + rx + 1) / 2;
            ly = (ly + ry + 1) / 2;
        }
    }

    ly += x;
    lx -= y;
    if (!(lx > 0 && lx <= (1LL << s.length()) && ly > 0 && ly <= (1LL << s.length()))) {
        cout << -1;
        return 0;
    }

    i = lx, j = ly;
    go("", 1, 1, 1LL << s.length(), 1LL << s.length());
}