#include <iostream>
#include <set>
using namespace std;

struct rec {
    int x1;
    int y1;
    int x2;
    int y2;
};

rec p[1001];
int pp[1001];

bool checkAdjecant(rec r1, rec r2) {
    if (r1.y2 < r2.y1) return false;
    if (r1.y1 > r2.y2) return false;
    if (r1.x2 < r2.x1) return false;
    if (r1.x1 > r2.x2) return false;
    if (r1.x1 < r2.x1 && r2.x2 < r1.x2 && r1.y2 > r2.y2 && r1.y1 < r2.y1) return false;
    if (r1.x1 > r2.x1 && r1.x2 < r2.x2 && r2.y2 > r1.y2 && r2.y1 < r1.y1) return false;

    return true;
}

int Find(int x) {
    if (pp[x] == x) {
        return x;
    }
    return pp[x] = Find(pp[x]);
}

void Union(int i, int j) {
    i = Find(i);
    j = Find(j);

    pp[i] = j;
}

int main() {
    int n;
    cin >> n;

    p[0] = {0, 0, 0, 0};

    for (int i = 1; i <= n; i++) {
        cin >> p[i].x1 >> p[i].y1 >> p[i].x2 >> p[i].y2;
        pp[i] = i;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (checkAdjecant(p[i], p[j])) {
                Union(i, j);
            }
        }
    }

    set<int> ans;

    for (int i = 0; i <= n; i++) {
        ans.insert(Find(i));
    }

    cout << ans.size() - 1;
}