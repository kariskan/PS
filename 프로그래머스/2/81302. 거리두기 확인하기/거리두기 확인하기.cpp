#include <string>
#include <vector>

using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dx2[4]={1,1,-1,-1};
int dy2[4]={1,-1,1,-1};
int n,m;
bool range(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(vector<string> place:places){
        n=place.size(),m=place[0].length();
        bool flag=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(place[i][j]=='P'){
                    for(int k=0;k<4;k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(range(nx,ny)&&place[nx][ny]=='P'){
                            flag=false;
                        }
                        nx=i+2*dx[k];
                        ny=j+2*dy[k];
                        if(range(nx,ny)&&place[nx][ny]=='P'&&place[nx-dx[k]][ny-dy[k]]!='X'){
                            flag=false;
                        }
                        nx=i+dx2[k];
                        ny=j+dy2[k];
                        if(range(nx,ny)&&place[nx][ny]=='P'&&(place[nx-dx2[k]][ny]!='X'||place[nx][ny-dy2[k]]!='X')){
                            flag=false;
                        }
                    }
                }
            }
        }
        if(flag){
            answer.push_back(1);
        }else{
            answer.push_back(0);
        }
    }
    return answer;
}