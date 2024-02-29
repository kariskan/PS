#include <string>
#include <vector>

using namespace std;
int map[1001][1001];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n=board.size(),m=board[0].size();
    for(vector<int> s:skill){
        int t=(s[0]==1?-s[5]:s[5]);
        map[s[1]][s[2]]+=t;
        map[s[1]][s[4]+1]-=t;
        map[s[3]+1][s[2]]-=t;
        map[s[3]+1][s[4]+1]+=t;
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