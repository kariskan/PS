#include <iostream>
#include <string>
using namespace std;

pair<int, int> next(int hour, int minute) {
    if (minute == 59) {
        if (hour == 23) {
            return {0, 0};
        }
        return {hour + 1, 0};
    }
    return {hour, minute + 1};
}

int getCost(int hour, int minute) {
    if (hour >= 7 && hour < 19) {
        return 10;
    }
    return 5;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        int m;
        cin >> s >> m;
        int hour = stoi(s.substr(0, 2));
        int minute = stoi(s.substr(3));
        while (m--) {
            ans += getCost(hour, minute);
            pair<int, int> ne = next(hour, minute);
            hour = ne.first;
            minute = ne.second;
        }
    }
    cout << ans;
}