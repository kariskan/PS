#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), compare);
    int pre = -1;
    for(int i=0;i<targets.size();i++){
        int start=targets[i][0];
        int end=targets[i][1];
        if(start>=pre){
            answer++;
            pre=end;
        }
    }
    
    return answer;
}