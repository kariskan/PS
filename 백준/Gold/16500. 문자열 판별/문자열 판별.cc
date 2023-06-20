#include <iostream>
#include <vector>
using namespace std;

string s;
string v[100];
int n, dp[100];

int main() {
    cin >> s >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < n; j++) {
            int len = v[j].length();
            if ((i == 0 || dp[i - 1]) && i + len <= s.length() &&
                s.substr(i, len) == v[j]) {
                dp[i + len - 1] = 1;
            }
        }
    }
    cout << dp[s.length() - 1];
}