#include <string>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<int> a;
long long answer;
long long go(int now,int pre){
    long long res=0;
    for(auto&i:v[now]){
        if(i!=pre){
            res+=go(i,now);
        }
    }
    answer+=abs(res-a[now]);
    return res-a[now];
}
long long solution(vector<int> a, vector<vector<int>> edges) {
    ::a=a;
    v.resize(a.size());
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    long long result=go(0,-1);
    return result==0?answer:-1;
}