#include <string>
#include <vector>

using namespace std;
int map[1001][1001];
vector<int> solution(int n) {
    vector<int> answer;
    int cnt=1;
    int k=n-1;
    for(int i=0;i<=(n-1)/3;i++){
        int startX=i*2+1;
        int startY=i+1;
        if(k==0){
            map[startX][startY]=cnt;
            break;
        }
        for(int j=0;j<k;j++){
            map[startX][startY]=cnt++;
            startX++;
        }
        for(int j=0;j<k;j++){
            map[startX][startY]=cnt++;
            startY++;
        }
        for(int j=0;j<k;j++){
            map[startX][startY]=cnt++;
            startX--;
        }
        k-=3;
    }
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            if(map[i][j]){
                answer.push_back(map[i][j]);
            }
        }
    }
    return answer;
}