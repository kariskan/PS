#include <iostream>
#include <vector>
using namespace std;
int map[51][51];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i=0;i<road.size();i++){
        if(map[road[i][0]][road[i][1]]==0||map[road[i][0]][road[i][1]]>road[i][2]){
            map[road[i][0]][road[i][1]]=road[i][2];
            map[road[i][1]][road[i][0]]=road[i][2];   
        }
    }
    
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i==j){
                    continue;
                }
                if(map[i][k]&&map[k][j]&&(map[i][j]==0||map[i][j]>map[i][k]+map[k][j])){
                    map[i][j]=map[i][k]+map[k][j];
                }
            }
        }
    }

    for(int i=1;i<=N;i++){
        if(map[1][i]<=K){
            answer++;
        }
    }
    return answer;
}