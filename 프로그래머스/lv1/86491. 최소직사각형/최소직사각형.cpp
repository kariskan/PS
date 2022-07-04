#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int a = max(sizes[0][0], sizes[0][1]), b = min(sizes[0][0], sizes[0][1]);
    for(int i=1;i<sizes.size();i++){
        int ta = sizes[i][0];
        int tb = sizes[i][1];
        if(ta<tb)swap(ta, tb);
        a = max(a, ta);
        b = max(b, tb);
    }
    return a * b;
}