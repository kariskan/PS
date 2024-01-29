#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(vector<int>& v1, vector<int>& v2){
    if(v1[0]==v2[0]){
        return v1[1]<v2[1];
    }
    return v1[0]>v2[0];
}

int solution(vector<vector<int>> scores) {
    int answer=0;
    vector<int> score=scores[0];
    
    int ma=0;
    sort(scores.begin(),scores.end(),compare);
    for(int i=0;i<scores.size();i++){
        if(ma>scores[i][1]){
            if(scores[i][0]==score[0]&&scores[i][1]==score[1]){
                return -1;
            }
        }else{
            ma=max(ma,scores[i][1]);
            if(score[0]+score[1]<scores[i][0]+scores[i][1]){
                answer++;
            }
        }
    }
    return answer+1;
}
