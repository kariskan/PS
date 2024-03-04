#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> v(n+1);
    for(int i=0;i<roads.size();i++){
        v[roads[i][0]].push_back(roads[i][1]);
        v[roads[i][1]].push_back(roads[i][0]);
    }
    
    vector<int> dis(n+1,987654321);
    priority_queue<pair<int,int>> pq;
    
    dis[destination]=0;
    pq.push({0,destination});
    
    while(!pq.empty()){
        int node=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        
        for(auto&i:v[node]){
            int nxNode=i;
            int nxCost=cost+1;
            if(nxCost<dis[nxNode]){
                dis[nxNode]=nxCost;
                pq.push({-nxCost,nxNode});
            }
        }
    }
    
    for(int i=0;i<sources.size();i++){
        if(dis[sources[i]]==987654321){
            answer.push_back(-1);
        }else{
            answer.push_back(dis[sources[i]]);
        }
    }
    return answer;
}