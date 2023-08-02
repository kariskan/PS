#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
pair<int, pair<int, char>> inp[1000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> inp[i].second.first >> inp[i].first >> inp[i].second.second;
    }
    sort(inp, inp + m);
    for (int i = 0; i < m; i++) {
        cout << inp[i].second.second;
    }
}