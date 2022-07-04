#include <string>
#include <vector>

using namespace std;
int a[1000001];
int solution(int n) {
    int answer = 0;
    
    for(int i = 2; i * i <= 1000000; i++) {
        if(!a[i]) {
            for(int j = i + i; j <= 1000000; j += i) {
                a[j] = 1;
            }
        }
    }
    
    for(int i = 2; i <= n; i++) {
        if(!a[i]) answer++;
    }
    
    return answer;
}