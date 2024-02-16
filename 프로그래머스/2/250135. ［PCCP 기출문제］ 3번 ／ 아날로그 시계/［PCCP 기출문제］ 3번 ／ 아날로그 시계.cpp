#include <string>
#include <vector>

using namespace std;

int rad(int s, int type) {
    if (type == 0) {
        return s % 43200;
    } else if (type == 1) {
        return (s % 3600) * 12;
    }
    return (s % 60) * 720;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    int H = rad(h1 * 3600 + m1 * 60 + s1, 0);
    int M = rad(h1 * 3600 + m1 * 60 + s1, 1);
    int S = rad(h1 * 3600 + m1 * 60 + s1, 2);
    for (int t = h1 * 3600 + m1 * 60 + s1 + 1; t <= h2 * 3600 + m2 * 60 + s2; t++) {
        int h = rad(t, 0);
        int m = rad(t, 1);
        int s = rad(t, 2);
        if (s == 0) {
            s = 43200;
        }
        bool HMatch = S < H && s >= h;
        bool MMatch = S < M && s >= m;
        if (HMatch) {
            answer++;
        }
        if (MMatch) {
            answer++;
        }
        if (s == 43200) {
            s = 0;
        }
        if (h == 0 && m == 0) {
            answer--;
        }
        H = h;
        M = m;
        S = s;
    }
    
    if ((h1 * 3600 + m1 * 60 + s1) % 43200 == 0) {
        answer++;
    }
    
    return answer;
}