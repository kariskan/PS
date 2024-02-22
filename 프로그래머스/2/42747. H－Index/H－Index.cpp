#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(int i=0;i<=10000;i++){
        for(int j=0;j<citations.size();j++){
            if(citations[j]>=i&&citations.size()-j>=i){
                answer=i;
                break;
            }
        }
    }
    return answer;
}