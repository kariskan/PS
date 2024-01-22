#include <string>
#include <vector>

using namespace std;
int child[101];
vector<vector<int>> v;

int getChildCnt(int n, int pre){
    int res=0;
    for(auto&i:v[n]){
        if(i != pre){
            res+=getChildCnt(i, n);
        }
    }
    return child[n]=res+1;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1000000000;
    v.resize(n+1);
    for(int i=0;i<wires.size();i++){
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }
    getChildCnt(1, 0);
    for(int i=0;i<wires.size();i++){
        int c1=child[wires[i][0]];
        int c2=child[wires[i][1]];
        if(c1<c2){
            swap(c1,c2);
        }
        answer=min(answer,abs(c2*2-n));
    }
    return answer;
}