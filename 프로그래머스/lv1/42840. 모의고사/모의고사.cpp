#include <string>
#include <vector>

using namespace std;
int ans[3][10]={{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ma = 0;
    int t1=0,t2=0,t3=0;
    for(int i=0;i<answers.size();i++){
        if(ans[0][i%5]==answers[i])t1++;
        if(ans[1][i%8]==answers[i])t2++;
        if(ans[2][i%10]==answers[i])t3++;
    }
    ma = max(t1, max(t2, t3));
    if(t1==ma)answer.push_back(1);
    if(t2==ma)answer.push_back(2);
    if(t3==ma)answer.push_back(3);
    return answer;
}