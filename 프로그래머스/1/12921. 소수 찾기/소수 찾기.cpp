#include <string>
#include <vector>

using namespace std;

int prime[1000001];

int solution(int n) {
    int answer = 0;
    for(int i=2;i*i<=n;i++){
        if(!prime[i]){
            for(int j=i*2;j<=n;j+=i){
                prime[j] = 1;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(!prime[i]){
            answer++;
        }
    }
    return answer;
}