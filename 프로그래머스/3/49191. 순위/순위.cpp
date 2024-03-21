#include <string>
#include <vector>
#include <cstring>
using namespace std;

int map[101][101];
int solution(int n, vector<vector<int>> results) {
    for(int i=0;i<results.size();i++){
        map[results[i][0]][results[i][1]]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(map[i][k]&&map[k][j]){
                    map[i][j]=1;
                }
            }
        }
    }
    int answer=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(map[i][j]||map[j][i]){
                cnt++;
            }
        }
        if(cnt==n-1){
            answer++;
        }
    }
    return answer;
}