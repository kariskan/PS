#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0, total = 0;
    string ansString = "";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a, b;
        cin >> a >> b;
        int cnt = 0;
        while (b >= a) {
            b -= a;
            b += 2;
            cnt++;
        }
        total += cnt;
        if (ans < cnt) {
            ans = cnt;
            ansString = s;
        }
    }
    cout << total << '\n' << ansString;
}