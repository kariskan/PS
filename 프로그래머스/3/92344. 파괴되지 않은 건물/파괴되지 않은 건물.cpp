#include <string>
#include <vector>

using namespace std;
int n,m;
int map[1001][1001];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    n=board.size();
    m=board[0].size();
    
    for(vector<int>&s:skill){
        int x1=s[1],y1=s[2],x2=s[3],y2=s[4],a=s[5];
        if(s[0]==1){//공격
            map[x1][y1]-=a;
            map[x1][y2+1]+=a;
            map[x2+1][y1]+=a;
            map[x2+1][y2+1]-=a;
        }else{
            map[x1][y1]+=a;
            map[x1][y2+1]-=a;
            map[x2+1][y1]-=a;
            map[x2+1][y2+1]+=a;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            map[i][j]+=map[i][j-1];
        }
    }
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            map[i][j]+=map[i-1][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map[i][j]+=board[i][j];
            if(map[i][j]>0){
                answer++;
            }
        }
    }
    return answer;
}