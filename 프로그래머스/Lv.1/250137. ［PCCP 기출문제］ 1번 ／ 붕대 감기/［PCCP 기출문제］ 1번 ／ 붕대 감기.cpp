#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int now = health, seq = 0, attackIdx = 0;
    for(int t = 1; t <= attacks[attacks.size() - 1][0]; t++) {
        if (t == attacks[attackIdx][0]) {
            seq = 0;
            now -= attacks[attackIdx++][1];
            if (now <= 0) {
                return -1;
            }
        } else {
            seq++;
            now = min(health, now + bandage[1]);
            if (seq == bandage[0]) {
                now = min(health, now + bandage[2]);
                seq = 0;
            }
        }
        printf("%d %d %d\n", t, now, seq);
    }
    
    return now;
}