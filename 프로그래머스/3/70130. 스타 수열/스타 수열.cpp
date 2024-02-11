#include <string>
#include <vector>

using namespace std;
int cnt[500001];
int solution(vector<int> a) {
    if(a.size()<2){
        return 0;
    }
    int answer = 2;
    
    int maxValue=0;
    for(int i=0;i<a.size();i++){
        cnt[a[i]]++;
        maxValue=max(maxValue,a[i]);
    }
    for(int i=0;i<=maxValue;i++){
        if(answer>=cnt[i]*2){
            continue;
        }
        int temp=0;
        for(int j=0;j<a.size()-1;j++){
            if((a[j]==i||a[j+1]==i)&&a[j]!=a[j+1]){
                j++;
                temp+=2;
                continue;
            }
        }
        answer=max(answer,temp);
    }
    
    return answer;
}