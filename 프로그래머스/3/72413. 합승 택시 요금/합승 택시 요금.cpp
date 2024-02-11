#include <string>
#include <vector>

using namespace std;

int map[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e9;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=-1;
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
                if(map[i][k]!=-1&&map[k][j]!=-1){
                    if(map[i][j]==-1||map[i][j]>map[i][k]+map[k][j]){
                        map[i][j]=map[i][k]+map[k][j];
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        if(map[a][i]!=-1&&map[b][i]!=-1&&map[i][s]!=-1){
            answer=min(answer,map[a][i]+map[b][i]+map[i][s]);
        }
    }
    return answer;
}