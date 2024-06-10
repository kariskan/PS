#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int dayOfMonth[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

int dateToMinute(int month, int day, int hour, int minute) {
    return dayOfMonth[month - 1] * 1440 + (day - 1) * 1440 + hour * 60 + minute;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, f;
    string s;
    cin >> n >> s >> f;
    long long l = stoi(s.substr(0, 3)) * 1440 + stoi(s.substr(4, 2)) * 60 + stoi(s.substr(7));
    map<string, map<string, int>> ma;
    map<string, long long> fine;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream ss(s);
        string temp;
        vector<string> v;
        while (getline(ss, temp, ' ')) {
            v.push_back(temp);
        }
        int m = dateToMinute(stoi(v[0].substr(5, 2)),
                             stoi(v[0].substr(8)),
                             stoi(v[1].substr(0, 2)),
                             stoi(v[1].substr(3)));
        if (ma[v[3]].find(v[2]) == ma[v[3]].end()) {
            ma[v[3]][v[2]] = m;
        } else {
            int pre = ma[v[3]][v[2]];
            if (m - pre > l) {
                fine[v[3]] += (m - pre - l) * f;
            }
            ma[v[3]].erase(v[2]);
        }
    }
    if (fine.empty()) {
        cout << -1;
    } else {
        for (auto &i: fine) {
            cout << i.first << ' ' << i.second << '\n';
        }
    }
}
