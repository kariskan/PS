#include <iostream>
using namespace std;

int n1, n2;
pair<char, int> a[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n1 >> n2;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < n1; i++) {
        a[i] = {s1[n1 - i - 1], 0};
    }
    for (int i = n1; i < n1 + n2; i++) {
        a[i] = {s2[i - n1], 1};
    }
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < n1 + n2 - 1; i++) {
            if (a[i].second == 0 && a[i + 1].second == 1) {
                swap(a[i], a[i + 1]);
                i++;
            }
        }
    }
    for (int i = 0; i < n1 + n2; i++) {
        cout << a[i].first;
    }
}