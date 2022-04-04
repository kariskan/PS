#include <string>
#include <vector>

using namespace std;
int ans = -1;
vector<string> s;
string t;
int visit[50];
int len;
void dfs(string now, int cnt) {
    if (now == t) {
        if (ans == -1 || ans > cnt) ans = cnt;
        return;
    }
    for (int i = 0; i < len; i++) {
        if (!visit[i]) {
            int change = 0;
            int nLen = now.length();
            for (int j = 0; j < nLen; j++) {
                if (now[j] != s[i][j]) {
                    change++;
                }
            }
            if (change <= 1) {
                visit[i] = 1;
                dfs(s[i], cnt + 1);
                visit[i] = 0;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    t = target;
    s = words;
    len = words.size();
    dfs(begin, 0);
    if (ans == -1)ans = 0;
    return ans;
}