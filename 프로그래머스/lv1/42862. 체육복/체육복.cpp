#include <string>
#include <vector>

using namespace std;
int a[32];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i=1;i<=n;i++)a[i]++;
    for(int i=0;i<reserve.size();i++){
        a[reserve[i]]++;
    }
    for(int i=0;i<lost.size();i++){
        a[lost[i]]--;
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",a[i]);
        if(a[i] == 0) {
            if(a[i-1] > 1){
                answer++;
                a[i-1]--;
            }
            else if(a[i+1] > 1){
                answer++;
                a[i+1]--;
            }
        }
        else {
            answer++;
        }
    }
    return answer;
}