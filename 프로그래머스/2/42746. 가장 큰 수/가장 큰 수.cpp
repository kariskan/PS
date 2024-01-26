#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int i, int j){
    return to_string(i)+to_string(j)>to_string(j)+to_string(i);
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),compare);
    for(int i=0;i<numbers.size();i++){
        answer+=to_string(numbers[i]);
    }
    while(answer.length()>1&&answer[0]=='0'){
        answer.erase(answer.begin());
    }
    return answer;
}