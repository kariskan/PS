#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(int n, vector<vector<int>> data) {
    int sum[5002][5002]={0,};
    map<int,int> xs,ys;
    int xCnt=1,yCnt=1;
    for(int i=0;i<data.size();i++){
        if(xs.find(data[i][0])==xs.end()){
            xs[data[i][0]]=0;
        }
        if(ys.find(data[i][1])==ys.end()){
            ys[data[i][1]]=0;
        }
    }
    for(auto&i:xs){
        i.second=xCnt++;
    }
    for(auto&i:ys){
        i.second=yCnt++;
    }
    for(int i=0;i<data.size();i++){
        data[i][0]=xs[data[i][0]];
        data[i][1]=ys[data[i][1]];
    }
    for(int i=0;i<data.size();i++){
        sum[data[i][0]][data[i][1]]=1;
    }
    for(int i=1;i<xCnt;i++){
        for(int j=1;j<yCnt;j++){
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int answer=0;
    for(int i=0;i<data.size();i++){
        for(int j=i+1;j<data.size();j++){
            int lux=min(data[i][0],data[j][0]);
            int luy=min(data[i][1],data[j][1]);
            int rdx=max(data[i][0],data[j][0]);
            int rdy=max(data[i][1],data[j][1]);

            if(lux==rdx||luy==rdy){
                continue;
            }
            if(sum[rdx-1][rdy-1]-sum[rdx-1][luy]-sum[lux][rdy-1]+sum[lux][luy]<=0){
                answer++;
            }
        }
    }
    return answer;
}
int main(){
    solution(4, {{0,1000000000},{1,1},{0,2},{2,0}});
}