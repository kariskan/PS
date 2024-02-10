#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n;
vector<vector<int>> rotate(vector<vector<int>> v) {
    int r=v.size(),c=v[0].size();
    vector<vector<int>> res(c,vector<int>(r));
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            res[i][j]=v[j][c-i-1];
        }
    }
    return res;
}
vector<vector<int>> bfs(vector<vector<int>>& vis,vector<vector<int>> board, int sx, int sy){
    queue<pair<int,int>>q,t;
    vis[sx][sy]=1;
    q.push({sx,sy});
    int minx=50,maxx=0,miny=50,maxy=0;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        t.push({x,y});
        minx=min(minx,x);
        maxx=max(maxx,x);
        miny=min(miny,y);
        maxy=max(maxy,y);

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&!vis[nx][ny]&&board[nx][ny]==board[x][y]){
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    vector<vector<int>> res(maxx-minx+1,vector<int>(maxy-miny+1));
    while(!t.empty()){
        res[t.front().first-minx][t.front().second-miny]=1;
        t.pop();
    }
    return res;
}

int solution(vector<vector<int>> board, vector<vector<int>> table) {
    n=board.size();
    int answer = 0;
    vector<vector<vector<int>>> v1,v2;
    vector<vector<int>> vis1(50,vector<int>(50)),vis2(50,vector<int>(50));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis1[i][j]&&!board[i][j]){
                v1.push_back(bfs(vis1,board,i,j));
            }
            if(!vis2[i][j]&&table[i][j]){
                v2.push_back(bfs(vis2,table,i,j));
            }
        }
    }
    int vis3[2500]={0,},vis4[2500]={0,};
    for(int i=0;i<v1.size();i++){
        if(vis3[i]){
            continue;
        }
        for(int j=0;j<v2.size();j++){
            if(vis4[j]){
                continue;
            }
            bool flag = false;
            for(int k=0;k<4;k++){
                v1[i]=rotate(v1[i]);
                if(v1[i].size()==v2[j].size()&&v1[i][0].size()==v2[j][0].size()){
                    bool flag2=true;
                    for(int i1=0;i1<v1[i].size();i1++){
                        for(int j1=0;j1<v1[i][0].size();j1++){
                            if(v1[i][i1][j1]!=v2[j][i1][j1]){
                                flag2=false;
                                break;
                            }
                        }
                        if(!flag2){
                            break;
                        }
                    }
                    if(flag2){
                        flag=true;
                        break;
                    }
                }
            }
            if(flag){
                vis4[j]=1;
                vis3[i]=1;
                for(int i1=0;i1<v1[i].size();i1++){
                    for(int j1=0;j1<v1[i][0].size();j1++){
                        if(v1[i][i1][j1]==1){
                            answer++;
                        }
                    }
                }
                break;
            }
        }
    }
    return answer;
}