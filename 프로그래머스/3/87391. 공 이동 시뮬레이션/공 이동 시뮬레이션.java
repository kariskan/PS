import static java.lang.Math.*;

class Solution {
    
    int[] dx = {0,0,1,-1};
    int[] dy = {1,-1,0,0};
    
    public long solution(int n, int m, int x, int y, int[][] queries) {
        long answer = -1;
        int sx = x, sy = y, ex = x, ey = y;
        for (int i = queries.length - 1; i >= 0; i--) {
            if (queries[i][0] == 0) {
                if (sy == 0) {
                    ey = min(m - 1, ey + queries[i][1]);
                } else {
                    if (sy + queries[i][1] >= m) {
                        return 0;
                    }
                    sy = min(m - 1, sy + queries[i][1]);
                    ey = min(m - 1, ey + queries[i][1]);
                }
            } else if (queries[i][0] == 1) {
                if (ey == m - 1) {
                    sy = max(0, sy - queries[i][1]);
                } else {
                    if (ey - queries[i][1] < 0) {
                        return 0;
                    }
                    sy = max(0, sy - queries[i][1]);
                    ey = max(0, ey - queries[i][1]);
                }
            } else if (queries[i][0] == 2) {
                if (sx == 0) {
                    ex = min(n - 1, ex + queries[i][1]);
                } else {
                    if (sx + queries[i][1] >= n) {
                        return 0;
                    }
                    sx = min(n - 1, sx + queries[i][1]);
                    ex = min(n - 1, ex + queries[i][1]);
                }
            } else {
                if (ex == n - 1) {
                    sx = max(0, sx - queries[i][1]);
                } else {
                    if (ex - queries[i][1] < 0) {
                        return 0;
                    }
                    sx = max(0, sx - queries[i][1]);
                    ex = max(0, ex - queries[i][1]);
                }
            }
        }
        return (long) (ex - sx + 1) * (ey - sy + 1);
    }
}