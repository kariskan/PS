#include <string>
#include <vector>
#include <queue>
using namespace std;
int map[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer=1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=5*1e8;
        }
    }
    for(int i=0;i<fares.size();i++){
        map[fares[i][0]][fares[i][1]]=fares[i][2];
        map[fares[i][1]][fares[i][0]]=fares[i][2];
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    map[i][j]=0;
                    continue;
                }
                if(map[i][j]==0||map[i][j]>map[i][k]+map[k][j]){
                    map[i][j]=map[i][k]+map[k][j];
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        answer=min(answer,map[s][i]+map[i][a]+map[i][b]);
    }
    return answer;
}