#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string s[10] = {"zero", "one", "two",   "three", "four",
                "five", "six", "seven", "eight", "nine"};

bool compare(pair<string, int> &p1, pair<string, int> &p2) {
    return p1.first < p2.first;
}

string parse(int n) {
    string res = "";
    if (n >= 10) {
        res += s[n / 10] + " ";
        n %= 10;
    }
    res += s[n];
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> v;
    for (int i = n; i <= m; i++) {
        v.push_back({parse(i), i});
    }

    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].second << ' ';
        cnt++;
        if (cnt == 10) {
            cout << '\n';
            cnt = 0;
        }
    }
}