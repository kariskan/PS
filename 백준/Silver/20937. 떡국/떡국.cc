#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> v;
map<int, int> ma;

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ma[a]++;
        ans = max(ans, ma[a]);
    }
    cout << ans;
}