#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, string> tree;
map<string, int> res;
void get(string s, int amount) {
    int div = amount / 10;
    res[s] += amount - div;
    if(div == 0) return;
    get(tree[s], div);
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i=0;i<enroll.size();i++){
        tree[enroll[i]] = referral[i];
    }
    
    for(int i=0;i<seller.size();i++){
        get(seller[i], amount[i] * 100);
    }
    
    for(int i=0;i<enroll.size();i++){
        answer.push_back(res[enroll[i]]);
    }
    
    return answer;
}