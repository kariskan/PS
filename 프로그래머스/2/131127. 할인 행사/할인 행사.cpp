#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int sum=0;
    map<string,int> ma;
    for(int i=0;i<number.size();i++){
        sum+=number[i];
        ma[want[i]]=number[i];
    }
    for(int i=0;i<=discount.size()-sum;i++){
        map<string,int> temp;
        for(int j=i;j<i+sum;j++){
            temp[discount[j]]++;
        }
        if(ma.size()!=temp.size()){
            continue;
        }
        bool flag=true;
        for(auto&i:ma){
            if(i.second!=temp[i.first]){
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