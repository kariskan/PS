#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n>s){
        return {-1};
    }
    vector<int> answer;
    while(n){
        answer.push_back(s/n);
        n--;
        s-=answer.back();
    }
    return answer;
}