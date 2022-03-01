#include <iostream>
#include <algorithm>
using namespace std;
int a[28];
bool compare(int a, int b) {
    return a > b;
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int len = s.length();
        int ten = 1;
        for (int j = len - 1; j >= 0; j--) {
            a[s[j] - 'A'] += ten;
            ten *= 10;
        }
    }
    sort(a, a + 28, compare);
    int ans = 0;
    int k = 9;
    for (int i = 0; i < 28; i++) {
        ans += a[i] * k--;
    }
    cout << ans;
}