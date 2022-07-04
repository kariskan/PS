#include <string>
#include <vector>

using namespace std;
int a[46];
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    for(int l:win_nums) {
        a[l] = 1;
    }
    int cnt = 0;
    int zeroCnt = 0;
    for(int w : lottos) {
        if(a[w]) cnt++;
        if(w==0)zeroCnt++;
    }
    if(cnt+zeroCnt>=2){
        answer.push_back(7-cnt-zeroCnt);
    }
    else answer.push_back(6);
    if(cnt>=2){
        answer.push_back(7 - cnt);
    }
    else answer.push_back(6);
    
    return answer;
}