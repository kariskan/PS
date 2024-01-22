#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> info;
pair<int, vector<int>> ans = {-1, {}};
int n;

pair<int, int> getScore(vector<int> res) {
    int rionScore = 0, peachScore = 0;
    for (int i = 0; i < info.size(); i++) {
        if (info[i] == 0 && res[i] == 0) {
            continue;
        }
        if (info[i] >= res[i]) {
            peachScore += 10 - i;
        } else {
            rionScore += 10 - i;
        }
    }
    return {peachScore, rionScore};
}

bool ok(vector<int> res) {
    for (int i = 10; i >= 0; i--) {
        if (res[i] == 0 && ans.second[i] == 0) {
            continue;
        }
        if (res[i] > ans.second[i]) {
            return true;
        } else break;
    }
    return false;
}

void go(int idx, vector<int> res, int N) {
    if (idx >= 10 || N == 0) {
        res[10] += N;
        pair<int, int> score = getScore(res);
        if (score.first >= score.second) {
            return;
        }
        if (ans.first < score.second - score.first || (ans.first == score.second - score.first && ok(res))) {
            ans = {score.second - score.first, res};
        }
        return;
    }
    if (N > info[idx]) {
        res[idx] = info[idx] + 1;
        go(idx + 1, res, N - info[idx] - 1);
        res[idx] = 0;
    }
    go(idx + 1, res, N);
}

vector<int> solution(int n, vector<int> info) {
    ::n = n;
    ::info = info;
    vector<int> res(11);
    go(0, res, n);
    if (ans.first == -1) {
        return {-1};
    }
    return ans.second;
}

int main() {
    ans.second = {0, 0, 2, 3, 4, 1, 0, 0, 0, 0, 0};
    ok({9, 0, 0, 0, 0, 0, 0, 1, 0, 0});
}