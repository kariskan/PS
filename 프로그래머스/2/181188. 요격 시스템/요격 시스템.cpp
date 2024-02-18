#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool compare(vector<int>& v1, vector<int>& v2){
    return v1[1]<v2[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(),targets.end(),compare);
	priority_queue<int> q;
    for(int i=0;i<targets.size();i++){
        int idx=i+1;
        while(idx<targets.size()&&targets[idx][0]<targets[i][1]){
            idx++;
        }
        answer++;
        i=idx-1;
    }
    return answer;
}