#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int map[102][102][2],n; // first=기둥,second=보

bool valid(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(map[i][j][0]){ // 기둥
                if(!(i==0||(j>0&&map[i][j-1][1])||map[i][j][1]||(i>0&&map[i-1][j][0]))){
                    return false;
                }
            }
            if(map[i][j][1]){
                if(!(i>0&&(map[i-1][j][0]||(j<=n-1&&map[i-1][j+1][0])||(j>0&&j<=n-2&&map[i][j-1][1]&&map[i][j+1][1])))){
                    return false;
                }
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    ::n=n;
    vector<vector<int>> answer;
    
    for(vector<int> build:build_frame){
        int x=build[1];
        int y=build[0];
        int type=build[2];
        int erase=build[3];
        
        map[x][y][type]=erase;
        if(!valid()){
            map[x][y][type]=1-erase;
        }
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<2;k++){
                if(map[i][j][k]){
                    answer.push_back({j,i,k});
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}