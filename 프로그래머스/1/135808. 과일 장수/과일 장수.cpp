#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(),score.end());
    int sum = 0,cnt=0;
    for(int i=score.size()-1;i>=0;i--){
        if(score[i]>k){
            continue;
        }
        cnt++;
        if(cnt==m){
            answer+=(score[i]*cnt);
            cnt=0;
        }
    }
    return answer;
}