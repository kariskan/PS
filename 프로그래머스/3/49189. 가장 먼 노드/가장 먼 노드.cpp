#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v;
int solution(int n, vector<vector<int>> edge) {
    v.resize(n+1);
    for(int i=0;i<edge.size();i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    vector<int> dis(n+1,1e9);
    priority_queue<pair<int,int>> pq;
    
    dis[1]=0;
    pq.push({0,1});
    int ma=0;
    while(!pq.empty()){
        int cost=-pq.top().first;
        int node=pq.top().second;
        pq.pop();
        ma=max(ma,dis[node]);
        if(dis[node]<cost){
            continue;
        }
        
        for(auto&i:v[node]){
            int nxNode=i;
            int nxCost=cost+1;
            if(dis[nxNode]>nxCost){
                dis[nxNode]=nxCost;
                pq.push({-nxCost,nxNode});
            }
        }
    }
    int answer=0;
    for(int i=2;i<=n;i++){
        if(ma==dis[i]){
            answer++;
        }
    }
    return answer;
}