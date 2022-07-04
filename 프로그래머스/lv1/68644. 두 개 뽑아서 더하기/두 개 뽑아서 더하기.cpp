#include <string>
#include <vector>
#include <set>
using namespace std;
set<int> s;
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0;i<numbers.size()-1;i++){
        for(int j=i+1;j<numbers.size();j++){
            if(s.find(numbers[i]+numbers[j])==s.end()) {
                s.insert(numbers[i]+numbers[j]);
            }
        }
    }
    for(auto i:s) {
        answer.push_back(i);
    }
    return answer;
}