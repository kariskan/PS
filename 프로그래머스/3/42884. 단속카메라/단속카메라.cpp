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
        // 최근 카메라 설치 지점보다 진입 지점이 크면
        if(k<routes[i][0]){
            answer++;
            // 나가는 지점에 카메라 설치
            k=routes[i][1];
        }
    }
    return answer;
}