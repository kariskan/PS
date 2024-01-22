#include <string>
#include <vector>

using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int map[101][101];

int rotate(int x1,int y1,int x2,int y2){
    int mi = map[x1][y1];
    int dir=0;
    int nx=x1;
    int ny=y1;
    int a = map[x1][y1];
    while(1){
        nx+=dx[dir];
        ny+=dy[dir];
        if(!(nx>=x1&&nx<=x2&&ny>=y1&&ny<=y2)){
            nx-=dx[dir];
            ny-=dy[dir];
            dir=(dir+1)%4;
            nx+=dx[dir];
            ny+=dy[dir];
        }
        int temp=map[nx][ny];
        map[nx][ny]=a;
        a=temp;
        mi=min(mi,a);
        if(nx==x1&&ny==y1){
            break;
        }
    }
    return mi;
}

vector<int> solution(int n, int m, vector<vector<int>> queries) {
    vector<int> answer;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            map[i][j]=(i-1)*m+j;
        }
    }
    for(int i=0;i<queries.size();i++){
        answer.push_back(rotate(queries[i][0],queries[i][1],queries[i][2],queries[i][3]));
    }
    
    return answer;
}