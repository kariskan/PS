#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(int i=0;i<balls.size();i++){
        int x=balls[i][0];
        int y=balls[i][1];
        int p=INT_MAX;
        if(y!=startY||x>startX){
            p=min(p,(x+startX)*(x+startX)+(y-startY)*(y-startY));
        }
        if(y!=startY||x<startX){
            p=min(p,(2*m-startX-x)*(2*m-startX-x)+(y-startY)*(y-startY));
        }
        if(x!=startX||y>startY){
            p=min(p,(x-startX)*(x-startX)+(y+startY)*(y+startY));
        }
        if(x!=startX||y<startY){
            p=min(p,(x-startX)*(x-startX)+(2*n-startY-y)*(2*n-startY-y));
        }
        answer.push_back(p);
    }
    return answer;
}