#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}
vector<pair<int, int>> v;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "order") {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        } else if (s == "sort") {
            sort(v.begin(), v.end(), compare);
        } else {
            int a;
            cin >> a;
            for (int j = 0; j < v.size(); j++) {
                if (v[j].first == a) {
                    v.erase(v.begin() + j);
                    break;
                }
            }
        }
        if (v.empty()) {
            cout << "sleep\n";
        } else {
            for (int j = 0; j < v.size(); j++) {
                cout << v[j].first << ' ';
            }
            cout << '\n';
        }
    }
}