#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> seq={'A','C','F','J','M','N','R','T'};
    do{
        bool flag=true;
        for(int i=0;i<data.size();i++){
            char first=data[i][0];
            char second=data[i][2];
            char eq=data[i][3];
            int term=data[i][4]-'0';
            int firstIdx,secondIdx;
            for(int j=0;j<seq.size();j++){
                if(seq[j]==first){
                    firstIdx=j;
                }
                if(seq[j]==second){
                    secondIdx=j;
                }
            }
            if(eq=='='){
                if(abs(firstIdx-secondIdx)!=term+1){
                    flag=false;
                    break;
                }
            }else if(eq=='>'){
                if(!(abs(firstIdx-secondIdx)>term+1)){
                    flag=false;
                    break;
                }
            }else{ //eq= '<'
                if(!(abs(firstIdx-secondIdx)<term+1)){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){
            answer++;
        }
    }while(next_permutation(seq.begin(),seq.end()));
    return answer;
}