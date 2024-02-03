#include <string>
#include <vector>
#include <queue>
using namespace std;
int vis[500];
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int cnt=jobs.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    for(int t=0;;t++){
        for(int i=0;i<jobs.size();i++){
            if(!vis[i]&&t>=jobs[i][0]){
                vis[i]=1;
                q.push({jobs[i][1],jobs[i][0]});
                cnt--;
            }
        }
        while(!q.empty()&&q.top().second<=t){
            // printf("%d %d %d\n", t, q.top().first, q.top().second);
            answer += t+q.top().first-q.top().second;
            t+=q.top().first;
            q.pop();
            // printf("%d\n", answer);
            
        for(int i=0;i<jobs.size();i++){
            if(!vis[i]&&t>=jobs[i][0]){
                vis[i]=1;
                q.push({jobs[i][1],jobs[i][0]});
                cnt--;
            }
        }
        }
        if(!cnt&&q.empty()){
            break;
        }
    }
    return answer/jobs.size();
}