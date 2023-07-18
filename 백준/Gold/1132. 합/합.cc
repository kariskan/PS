#include <algorithm>
#include <iostream>
using namespace std;

string s[50];
int n;
pair<long long, bool> a[10];

int main() {
    cin >> n;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cin >> s[i];

        long long p = 1;
        for (int j = s[i].length() - 1; j >= 0; j--) {
            if (j == 0) {
                a[s[i][j] - 'A'].second = true;
            }
            if (!a[s[i][j] - 'A'].first) {
                cnt++;
            }
            a[s[i][j] - 'A'].first += p;
            p *= 10;
        }
    }

    sort(a, a + 10, [](auto &a, auto &b) { return a.first > b.first; });

    long long t = 9;
    long long ans = 0;

    if (cnt == 10 && a[9].second == true) {
        for (int i = 8; i >= 0; i--) {
            if (a[i].second == false) {
                pair<long long, bool> temp = a[i];
                for (int j = i; j < 9; j++) {
                    a[j] = a[j + 1];
                }
                a[9] = temp;
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        ans += (t--) * a[i].first;
    }
    cout << ans;
}