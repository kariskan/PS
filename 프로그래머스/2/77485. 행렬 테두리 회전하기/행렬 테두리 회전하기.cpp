#include <string>
#include <vector>

using namespace std;
int map[101][101];
vector<int> solution(int n, int m, vector<vector<int>> queries) {
    vector<int> answer;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            map[i][j]=(i-1)*m+j;
        }
    }
    for(vector<int> q:queries){
        int mi=map[q[0]][q[1]];
        int pre=map[q[0]][q[1]];
        for(int i=q[0];i<q[2];i++){
            map[i][q[1]]=map[i+1][q[1]];
            mi=min(mi,map[i][q[1]]);
        }
        for(int i=q[1];i<q[3];i++){
            map[q[2]][i]=map[q[2]][i+1];
            mi=min(mi,map[q[2]][i]);
        }
        for(int i=q[2];i>q[0];i--){
            map[i][q[3]]=map[i-1][q[3]];
            mi=min(mi,map[i][q[3]]);
        }
        for(int i=q[3];i>q[1];i--){
            map[q[0]][i]=map[q[0]][i-1];
            if(i==q[1]+1){
                map[q[0]][i]=pre;
            }
            mi=min(mi,map[q[0]][i]);
        }
        answer.push_back(mi);
    }
    return answer;
}