#include <string>
#include <vector>

using namespace std;

int map[100001];

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    for(int sec:section){
        map[sec]=1;
    }
    
    for(int i=1;i<=n;i++){
        if(map[i]){
            answer++;
            i+=m-1;
        }
    }
    
    return answer;
}