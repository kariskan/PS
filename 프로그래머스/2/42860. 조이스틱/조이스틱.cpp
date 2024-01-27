#include <string>
#include <vector>

using namespace std;

int get(char a) {
    return min(a - 'A', 1 + 'Z' - a);
}

int solution(string name) {
    int answer = 0;
    int m = name.length() - 1;
    for (int i = 0; i < name.length(); i++) {
        int idx = i + 1;
        while (idx < name.length() && name[idx] == 'A') {
            idx++;
        }
        m = min(m, i * 2 + (int) name.length() - idx);
        m = min(m, ((int)name.length() - idx) * 2 + i);
    }
    for (int i = 0; i < name.length(); i++) {
        answer += get(name[i]);
    }
    return answer + m;
}