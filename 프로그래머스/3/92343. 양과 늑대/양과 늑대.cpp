#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v;
int answer;
vector<int> info;

void go(int now,int sheep, int wolf, queue<int> q){
    if(sheep<=wolf){
        return;
    }
    answer=max(answer,sheep);
    for(auto&i:v[now]){
        q.push(i);
    }
    int siz=q.size();
    for(int i=0;i<siz;i++){
        int node=q.front();
        q.pop();
        go(node,sheep+1-info[node],wolf+info[node],q);
        q.push(node);
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    ::info=info;
    v.resize(info.size());
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
    }
    queue<int> q;
    go(0,1,0,q);
    return answer;
}