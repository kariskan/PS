#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> ma;
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i=0;i<9;i++){
        ma[discount[i]]++;
    }
    for(int i=9;i<discount.size();i++){
        ma[discount[i]]++;
        if(i-10>=0){
            ma[discount[i-10]]--;
        }
        bool flag = true;
        for(int j=0;j<number.size();j++){
            if(ma[want[j]]!=number[j]){
                flag=false;
                break;
            }
        }
        if(flag){
            answer++;
        }
    }
    return answer;
}