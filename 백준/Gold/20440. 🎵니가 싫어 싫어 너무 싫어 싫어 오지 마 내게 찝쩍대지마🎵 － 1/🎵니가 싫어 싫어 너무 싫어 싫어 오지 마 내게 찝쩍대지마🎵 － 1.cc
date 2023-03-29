#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, pos[2000010];
pair<int, int> inp[1000001];
vector<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inp[i].first >> inp[i].second;
        s.push_back(inp[i].first);
        s.push_back(inp[i].second);
    }

    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    
    vector<int> a(s.size());

    for (int i = 0; i < n; i++) {
        int l = lower_bound(s.begin(), s.end(), inp[i].first) - s.begin();
        int r = lower_bound(s.begin(), s.end(), inp[i].second) - s.begin();

        a[l]++;
        a[r]--;

        pos[l] = inp[i].first;
        pos[r] = inp[i].second;
    }

    for (int i = 1; i <= s.size(); i++) {
        a[i] += a[i - 1];
    }
    int ans = *max_element(a.begin(), a.end()), ansl = -1, ansr;
    for (int i = 0; i < s.size(); i++) {
        if (ans == a[i] && ansl == -1) {
            ansl = pos[i];
        }
        if (ans != a[i] && ansl != -1) {
            ansr = pos[i];
            break;
        }
    }

    cout << ans << '\n' << ansl << ' ' << ansr;
}