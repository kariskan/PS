#include <string>
#include <vector>

using namespace std;

int dx[3]={1,0,-1};
int dy[3]={0,1,-1};
int map[1000][1000];
vector<int> solution(int n) {
    vector<int> answer;
    int x=-1,y=0,dir=0,num=1;
    for(int i=n;i>=1;i--){
        for(int j=0;j<i;j++){
            x+=dx[dir];
            y+=dy[dir];
            map[x][y]=num++;
        }
        dir=(dir+1)%3;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            answer.push_back(map[i][j]);
        }
    }
    return answer;
}