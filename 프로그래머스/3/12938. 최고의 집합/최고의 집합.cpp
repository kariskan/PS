#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n>s){
        return {-1};
    }
    vector<int> answer;
    int N=n;
    for(int i=0;i<N;i++){
        answer.push_back(s/n);
        s-=answer.back();
        n--;
    }
    return answer;
}