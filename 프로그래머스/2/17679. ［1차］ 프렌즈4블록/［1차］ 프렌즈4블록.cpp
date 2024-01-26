#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[3]={0,1,1};
int dy[3]={1,0,1};
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1){
        queue<pair<int, int>> q;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                if(board[i][j]==' '){
                    continue;
                }
                bool flag=true;
                for(int k=0;k<3;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(!(nx>=0&&nx<m&&ny>=0&&ny<n&&board[nx][ny]==board[i][j])){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    q.push({i,j});
                    for(int k=0;k<3;k++){
                        q.push({i+dx[k],j+dy[k]});
                    }
                }
            }
        }
        if(q.empty()){
            break;
        }
        while(!q.empty()){
            board[q.front().first][q.front().second]=' ';
            q.pop();
        }
        for(int j=0;j<n;j++){
            for(int i=m-1;i>=0;i--){
                if(board[i][j]==' '){
                    int idx=i;
                    while(idx>0&&board[idx][j]==' '){
                        idx--;
                    }
                    board[i][j]=board[idx][j];
                    board[idx][j] = ' ';
                }
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==' '){
                answer++;
            }
        }
    }
    return answer;
}