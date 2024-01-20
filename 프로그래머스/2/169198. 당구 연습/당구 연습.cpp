#include <string>
#include <vector>

using namespace std;

int getDis(int x, int y, int x2, int y2){
    return (x-x2)*(x-x2)+(y-y2)*(y-y2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i=0;i<balls.size();i++){
        int x=balls[i][0],y=balls[i][1];
        int ans=1000000000;
        if(!(startY==y&&x>startX)){
            ans=min(ans,getDis(startX,startY,m*2-x,y));
        }
        if(!(startY==y&&x<startX)){
            ans=min(ans,getDis(startX,startY,-x,y));
        }
        if(!(startX==x&&y<startY)){
            ans=min(ans,getDis(startX,startY,x,-y));
        }
        if(!(startX==x&&y>startY)){
            ans=min(ans,getDis(startX,startY,x,2*n-y));
        }
        answer.push_back(ans);
    }
    
    return answer;
}