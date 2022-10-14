#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e, p;
vector<vector<pair<int, int>>> map;

int dijk(int source, int destination) {
    
    vector<int> dis(v + 1, 987654321);
    priority_queue<pair<int, int>> pq;
    pq.push({0,source});
    dis[source] = 0;
    
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        
        for(auto&i:map[node]) {
            int nxNode = i.first;
            int nxCost = cost + i.second;
            
            if(dis[nxNode] > nxCost) {
                dis[nxNode] = nxCost;
                pq.push({-nxCost,nxNode});
            }
        }
    }
    
    return dis[destination];
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>v>>e>>p;
    map.resize(v+1);
    
    for(int i=0;i<e;i++){
        int a,b,c;cin>>a>>b>>c;
        map[a].push_back({b,c});
        map[b].push_back({a,c});
    }
    
    int StoP = dijk(1, p);
    int PtoD = dijk(p, v);
    int StoD = dijk(1, v);
    
    if(StoP + PtoD == StoD) {
        cout<<"SAVE HIM\n";
    }
    else cout<<"GOOD BYE\n";
}
