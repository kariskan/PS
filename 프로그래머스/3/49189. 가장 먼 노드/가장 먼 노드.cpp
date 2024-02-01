#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
int vis[20001];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vis[1]=1;
    q.push(1);
    vector<vector<int>> v(n+1);
    for(int i=0;i<edge.size();i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    int ma=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ma=vis[node];
        for(auto&i:v[node]){
            if(!vis[i]){
                vis[i]=vis[node]+1;
                q.push(i);
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(vis[i]==ma){
            answer++;
        }
    }
    return answer;
}