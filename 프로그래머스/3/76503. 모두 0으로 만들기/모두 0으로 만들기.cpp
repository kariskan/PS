#include <string>
#include <vector>

using namespace std;
long long answer=0;
vector<vector<int>> v;
vector<int> a;

long long go(int now,int pre){
    
    long long res=0,p=0;
    for(auto&i:v[now]){
        if(i!=pre){
            long long g=go(i,now);
            res+=g;
            p+=abs(g);
        }
    }
    answer+=a[now]+p;
    return a[now]+res;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    ::a=a;
    v.resize(a.size());
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    return go(0,-1)==0?answer:-1;
}