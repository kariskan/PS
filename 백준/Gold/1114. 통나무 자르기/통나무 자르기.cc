#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int l, k, c;
    cin >> l >> k >> c;
    for (int i = 1; i <= k; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    v.push_back(l);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int left = 1, right = l;
    int ans, ansf; // 통나무의 가장 긴 조각, 그 때의 위치
    while (left <= right) {
        int mid = (left + right) / 2;
        
        // 이전의 자를 위치, 남은 자를 수 있는 횟수
        int prev = l, cnt = c;
        bool flag = true;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (prev - v[i] > mid) { // 이전에 자른 위치와 비교해 크면
                if (v[i + 1] - v[i] > mid) { // 바로 앞의 위치가 mid 보다 크면 자를 수 없다
                    flag = false;
                    break;
                }
                cnt--; // 자른다
                prev = v[i + 1]; 
                if (cnt == 0) {
                    break;
                }
            }
        }
        
        // 자를 수 있는 횟수가 남았으면 최대한 처음 자르는 위치는 작게 해야한다
        if (cnt > 0) {
            prev = v[0]; 
        }
        
        // 처음 자르는 위치가 mid 보다 크면
        if (prev > mid) {
            flag = false;
        }
        
        if (!flag) {
            left = mid + 1;
        } else {
            right = mid - 1;
            ans = mid;
            ansf = prev;
        }
    }
    cout << ans << ' ' << ansf;
}