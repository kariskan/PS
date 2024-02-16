#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
int in[1000001],out[1000001],vis[1000001];
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer={0,0,0,0};
    v.resize(1000001);
    int n=0;
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
        in[edges[i][1]]++;
        out[edges[i][0]]++;
        n=max(n,max(edges[i][0],edges[i][1]));
    }
    int start;
    for(int i=1;i<=n;i++){
        if(out[i]>=2&&in[i]==0){
            start=i;
            break;
        }
    }
    
    int total=v[start].size();
    
    for(int i=0;i<v[start].size();i++){
        int node=0,edge=0;
        int now=v[start][i];
        queue<int> q;
        q.push(now);
        vis[now]=1;
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
            node++;
            edge+=v[x].size();
            for(auto&i:v[x]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        if(node==edge){
            answer[1]++;
        }else if(node==edge+1){
            answer[2]++;
        }else{
            answer[3]++;
        }
    }
    answer[0]=start;
    return answer;
}