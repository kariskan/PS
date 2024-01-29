#include <string>
#include <vector>
using namespace std;
// 1~20싱글, 1~20더블, 1~20트리플, 불(50)
pair<int,int> dp[100001];
vector<int> solution(int target) {
    vector<int> answer;
    for(int i=0;i<=target;i++){
        dp[i]={100000,100000};
    }
    dp[0]={0,0};
    for(int i=0;i<=target;i++){
        for(int j=1;j<=20;j++){
            for(int k=1;k<=3;k++){
                int nxScore = i + j * k;
                int additional = (k == 1 ? 1 : 0);
                if (nxScore > target) {
                    continue;
                }
                if (dp[nxScore].first > dp[i].first + 1 
                    || (dp[nxScore].first == dp[i].first + 1 && dp[nxScore].second < dp[i].second + additional)) {
                    dp[nxScore] = {dp[i].first + 1,dp[i].second + additional};
                }
            }
            int nxScore = i + 50;
            if (nxScore > target) {
                continue;
            }
            if (dp[nxScore].first > dp[i].first + 1
               || (dp[nxScore].first == dp[i].first + 1 && dp[nxScore].second < dp[i].second + 1)) {
                dp[nxScore] = {dp[i].first + 1,dp[i].second + 1};
            }
        }
    }
    
    return {dp[target].first, dp[target].second};
}