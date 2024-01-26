#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    for(int i=0;i<=citations.size();i++){
        int hup=0,hdown=0;
        for(int j=0;j<citations.size();j++){
            if(citations[j]>=i){
                hup++;
            }
            if(citations[j]<=i){
                hdown++;
            }
        }
        if(hup>=i&&hdown<=i){
            answer=max(answer,i);
        }
    }
    return answer;
}