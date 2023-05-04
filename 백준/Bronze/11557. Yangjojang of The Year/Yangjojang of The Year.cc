#include <algorithm>
#include <iostream>
using namespace std;

pair<string, int> inp[100];

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> inp[i].first >> inp[i].second;
        }
        sort(inp, inp + m, [](const pair<string, int>& a, const pair<string, int>& b) { return a.second > b.second; });

        cout << inp[0].first << '\n';
    }
}