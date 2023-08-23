#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'C') {
            cnt++;
        }
    }
    cout << ceil((s.length() - cnt) / ((double)cnt + 1));
}