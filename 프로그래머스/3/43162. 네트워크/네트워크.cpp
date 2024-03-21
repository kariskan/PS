#include <string>
#include <vector>

using namespace std;

int vis[200];
vector<vector<int>> computers;
void go(int node){
    for(int i=0;i<computers.size();i++){
        if(!vis[i]&&computers[node][i]){
            vis[i]=1;
            go(i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    ::computers=computers;
    int answer = 0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            go(i);
            answer++;
        }
    }
    return answer;
}