#include <string>
#include <vector>

using namespace std;
vector<vector<int>> v;
int answer = 100,n;
int go(int now,int pre){
    int res=0;
    for(auto&i:v[now]){
        if(i==pre){
            continue;
        }
        int child=go(i,now);
        answer=min(answer,abs(2*child-n));
        res+=child;
    }
    return res+1;
}
int solution(int n, vector<vector<int>> wires) {
    v.resize(n+1);
    ::n=n;
    for(int i=0;i<wires.size();i++){
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    go(1,0);
    return answer;
}