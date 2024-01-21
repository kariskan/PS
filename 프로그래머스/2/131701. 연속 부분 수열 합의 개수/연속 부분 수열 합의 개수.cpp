#include <string>
#include <vector>
#include <set>
using namespace std;
set<int> s;
int solution(vector<int> elements) {
    for(int i=1;i<=elements.size();i++){
        for(int start=0;start<elements.size();start++){
            int sum=0;
            for(int cnt=0;cnt<i;cnt++){
                sum+=elements[(start+cnt)%elements.size()];
            }
            s.insert(sum);
        }
    }
    return s.size();
}