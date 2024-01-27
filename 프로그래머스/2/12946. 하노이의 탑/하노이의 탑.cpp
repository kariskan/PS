#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
void go(int n, int source, int target, int other){
    if(n==1){
        answer.push_back({source,target});
        return;
    }
    go(n - 1, source, other, target);
    answer.push_back({source, target});
    go(n - 1, other, target, source);
}
vector<vector<int>> solution(int n) {
    go(n, 1, 3, 2);
    return answer;
}