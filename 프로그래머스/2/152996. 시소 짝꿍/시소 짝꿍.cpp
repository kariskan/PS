#include <string>
#include <vector>

using namespace std;

int weight[1001];

long long solution(vector<int> weights) {
    long long answer = 0;
    for(int i=0;i<weights.size();i++){
        weight[weights[i]]++;
    }
    for(int i=1;i<=1000;i++){
        answer += (long long)weight[i] * (weight[i] - 1) / 2;
    }
    long long a = 0;
    for(int i=0;i<weights.size();i++){
        for(int j=2;j<=4;j++){
            for(int k=2;k<=4;k++){
                if(j==k){
                    continue;
                }
                if((weights[i]*j)%k==0&&(weights[i]*j)/k<=1000){
                    a+=weight[(weights[i]*j)/k];
                }
            }
        }
    }
    return answer+a/2;
}