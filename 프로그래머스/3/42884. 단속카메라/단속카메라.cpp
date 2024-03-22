#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool compare(vector<int>& v1,vector<int>& v2){
    return v1[1]<v2[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),compare);
    int k=routes[0][1];
    answer=1;
    for(int i=0;i<routes.size();i++){
        if(k<routes[i][0]){
            answer++;
            k=routes[i][1];
        }
    }
    return answer;
}