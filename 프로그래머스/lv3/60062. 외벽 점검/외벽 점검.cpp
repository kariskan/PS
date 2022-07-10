#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a, int b) {
    return a > b;
}
int t[200];
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    vector<int> seq(dist.size());
    for(int i=0;i<dist.size();i++)seq[i]=i;
    for (int i = 0; i < weak.size(); i++)t[weak[i]] = 1;
    do{
        for (int i = 0; i < weak.size(); i++) {
        int idx = weak[i]; //점검 시작할 곳
        int visit[200] = { 0, };
        for (int j = 0; j < dist.size(); j++) {
            int now = dist[seq[j]];
            for (int k = idx; k <= now + idx; k++) {
                visit[k % n] = 1; //점검 했음
            }
            int cnt = n;
            for (int k = (idx + now + 1) % n; cnt; k=(k+1)%n) {
                if (!visit[k] && t[k]) {
                    idx = k;
                    break;
                }
                cnt--;
            }
            int ok = 1;
            for (int k = 0; k < weak.size(); k++) {
                if (visit[weak[k]] == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                if (answer == -1 || answer > j + 1) {
                    answer = j + 1;
                }
                break;
            }
        }
    }
    }while(next_permutation(seq.begin(), seq.end()));
    
    return answer;
}