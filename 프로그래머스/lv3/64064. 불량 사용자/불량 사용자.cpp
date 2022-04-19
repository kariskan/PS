#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<string> user;
vector<string> ban;
set<vector<string>> m;
int n;
int bn;
int visit[8];
int banVisit[8];
int answer = 0;
void dfs(int idx, int cnt, vector<string> ans) {
    if (cnt == bn) {
        sort(ans.begin(), ans.end());
        if (m.find(ans) != m.end())return;
        m.insert(ans);
        answer++;
        return;
    }


    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            int ok = 0;
            int okIdx = 0;
            for (int j = 0; j < bn; j++) {
                if (!banVisit[j] && user[i].length() == ban[j].length()) {
                    int brk = 1;
                    for (int k = 0; k < user[i].length(); k++) {
                        if (ban[j][k] == '*')continue;
                        if (ban[j][k] != user[i][k]) {
                            brk = 0;
                            break;
                        }
                    }
                    if (brk) {
                        ok = 1;
                        okIdx = j;
                        break;
                    }
                }
            }
            if (!ok)continue;
            banVisit[okIdx] = 1;
            visit[i] = 1;
            ans.push_back(user[i]);
            dfs(i, cnt + 1, ans);
            ans.pop_back();
            visit[i] = 0;
            banVisit[okIdx] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    user = user_id;
    ban = banned_id;
    n = user.size();
    bn = ban.size();
    dfs(-1, 0, {});
    return answer;
}