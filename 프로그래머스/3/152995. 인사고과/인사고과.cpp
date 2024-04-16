#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(vector<int>& v1,vector<int>& v2){
    if(v1[0]==v2[0]){
        return v1[1]<v2[1];
    }
    return v1[0]>v2[0];
}
int solution(vector<vector<int>> scores) {
    int answer=1;
    int x=scores[0][0], y=scores[0][1];
    sort(scores.begin(),scores.end(),compare);
    
    int ma=0;
    for(int i=0;i<scores.size();i++){
        ma=max(ma,scores[i][1]);
        if(ma>scores[i][1]){
            if(scores[i][0]==x&&scores[i][1]==y){
                return -1;
            }
        }else{
            if(x+y<scores[i][0]+scores[i][1]){
                answer++;
            }
        }
    }
    return answer;
}