#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//기둥일때 first, 보일때 second
pair<int,int> map[102][102];
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(vector<int>& build:build_frame){
        int x=build[1],y=build[0];
        if(build[2]==0){
            map[x][y].first=build[3];
        }else{
            map[x][y].second=build[3];
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(map[i][j].first){
                    if(!(i==0
                         ||map[i][j].second
                         ||(j>0&&map[i][j-1].second)
                         ||(i>0&&map[i-1][j].first))){
                        if(build[2]==0){
                            map[x][y].first=1-build[3];
                        }else{
                            map[x][y].second=1-build[3];
                        }
                    }
                }
                if(map[i][j].second){
                    if(!((i>0&&map[i-1][j].first)
                         ||(i>0&&map[i-1][j+1].first)
                         ||(j>0&&map[i][j-1].second&&map[i][j+1].second))){
                        if(build[2]==0){
                            map[x][y].first=1-build[3];
                        }else{
                            map[x][y].second=1-build[3];
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(map[i][j].first){
                answer.push_back({j,i,0});
            } 
            if(map[i][j].second){
                answer.push_back({j,i,1});
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}