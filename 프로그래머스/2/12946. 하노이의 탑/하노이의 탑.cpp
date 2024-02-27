#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
//          1       3       2
void go(int from, int to, int other,int n){
    if(n==0){
        return;
    }
    go(from,other,to,n-1);
    answer.push_back({from,to});
    go(other,to,from,n-1);
}

vector<vector<int>> solution(int n) {
    go(1,3,2,n);
    return answer;
}