#include <iostream>
using namespace std;

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int year, int month) {
    if (month != 2) {
        return false;
    }
    if (year % 100 == 0 && year % 400 != 0) {
        return false;
    }
    return year % 4 == 0;
}

int main() {
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    int ans = 0;
    if ((y1 + 1000 == y2 && m1 == m2 && d1 == d2) || y1 + 1000 < y2) {
        cout << "gg";
        return 0;
    }
    while (y1 != y2 || m1 != m2 || d1 != d2) {
        d1++;

        int dayOfMonth = check(y1, m1) ? 29 : day[m1];

        if (d1 > dayOfMonth) {
            m1++;
            d1 = 1;
            if (m1 > 12) {
                y1++;
                m1 = 1;
            }
        }

        ans++;
    }
    
    cout << "D-" << ans;
}