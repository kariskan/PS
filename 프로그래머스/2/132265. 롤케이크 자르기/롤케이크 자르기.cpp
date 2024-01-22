#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> m1,m2;

int solution(vector<int> topping) {
    int answer = 0;
    for(int i=0;i<topping.size();i++){
        m2[topping[i]]++;
    }
    for(int i=1;i<topping.size();i++){
        m2[topping[i-1]]--;
        if(m2[topping[i-1]]==0){
            m2.erase(topping[i-1]);
        }
        m1[topping[i-1]]++;
        
        if(m1.size()==m2.size()){
            answer++;
        }
    }
    return answer;
}