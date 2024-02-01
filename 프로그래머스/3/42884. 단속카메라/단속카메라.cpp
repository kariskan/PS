#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>&v1,vector<int>&v2){
    return v1[1]<v2[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end(),compare);
    for(int i=0;i<routes.size();i++){
        answer++;
        int idx=i+1;
        while(idx<routes.size()&&routes[idx][0]<=routes[i][1]){
            idx++;
        }
        i=idx-1;
    }
    return answer;
}