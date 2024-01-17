#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 1000000000;
    int maxR = 0, maxC = 0;
    for(int i=0;i<sizes.size();i++){
        if (max(maxR, sizes[i][0]) * max(maxC, sizes[i][1]) < 
           max(maxR, sizes[i][1]) * max(maxC, sizes[i][0])) {
            maxR = max(maxR, sizes[i][0]);
            maxC = max(maxC, sizes[i][1]);
            answer = max(maxR, sizes[i][0]) * max(maxC, sizes[i][1]);
        } else {
            maxR = max(maxR, sizes[i][1]);
            maxC = max(maxC, sizes[i][0]);
            answer = max(maxR, sizes[i][1]) * max(maxC, sizes[i][0]);
        }
    }
    return answer;
}