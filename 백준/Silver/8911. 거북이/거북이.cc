#include <iostream>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int x = 0, y = 0, dir = 0;
        int leftx = 0, lefty = 0, rightx = 0, righty = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'F') {
                x += dx[dir];
                y += dy[dir];
            } else if (s[i] == 'B') {
                x += dx[(dir + 2) % 4];
                y += dy[(dir + 2) % 4];
            } else if (s[i] == 'L') {
                dir = (dir + 3) % 4;
            } else { // R
                dir = (dir + 1) % 4;
            }
            leftx = min(leftx, x);
            lefty = min(lefty, y);
            rightx = max(rightx, x);
            righty = max(righty, y);
        }

        cout << (rightx - leftx) * (righty - lefty) << '\n';
    }
}