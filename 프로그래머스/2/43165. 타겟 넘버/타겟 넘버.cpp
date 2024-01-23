#include <string>
#include <vector>

using namespace std;
vector<int> numbers;
int target,answer;
void go(int sum, int idx){
    if(idx>=numbers.size()){
        if(sum==target){
            answer++;
        }
        return;
    }
    go(sum-numbers[idx],idx+1);
    go(sum+numbers[idx],idx+1);
}

int solution(vector<int> numbers, int target) {
    ::numbers=numbers;
    ::target=target;
    go(0,0);
    return answer;
}