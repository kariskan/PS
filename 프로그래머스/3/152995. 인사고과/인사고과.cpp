#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int flag[100000];
bool compare(vector<int>& v1,vector<int>& v2){
    if(v1[0]==v2[0]){
        return v1[1]>v2[1];
    }
    return v1[0]>v2[0];
}
int solution(vector<vector<int>> scores) {
    int answer=1;
    int x=scores[0][0], y=scores[0][1];
    sort(scores.begin(),scores.end(),compare);
    
    vector<vector<int>> v={{scores[0][0],scores[0][1]}};
    for(int i=1;i<scores.size();i++){
        if(scores[i][0]!=v.back()[0]){
            v.push_back({scores[i][0],scores[i][1]});
            
        }
    }
    
    for(int i=0;i<scores.size();i++){
        for(int j=0;j<v.size();j++){
            // printf("%d %d %d %d \n", scores[i][0],scores[i][1], v[j][0],v[j][1]);
            if(scores[i][0]>=v[j][0]){
                break;
            }
            if(v[j][1]>scores[i][1]){
                flag[i]=1;
                if(scores[i][0]==x&&scores[i][1]==y){
                    return -1;
                }
                break;
            }
        }
        if(!flag[i]&&x+y<scores[i][0]+scores[i][1]){
            answer++;
        }
    }
    return answer;
}