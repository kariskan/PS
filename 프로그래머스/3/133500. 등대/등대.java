import java.util.*;

class Solution {
    
    int[][] dp = new int[100001][2];
    List<List<Integer>> v = new ArrayList<>();
    int n;
    
    public int solution(int n, int[][] lighthouse) {
        this.n = n;
        for (int i = 0; i <= n; i++) {
            v.add(new ArrayList<>());
        }
        for (int[] light : lighthouse) {
            v.get(light[0]).add(light[1]);
            v.get(light[1]).add(light[0]);
        }
        return Math.min(go(1, 0, 0), go(1, 0, 1));
    }
    
    int go(int node, int pre, int flag) {
        if (dp[node][flag] > 0) {
            return dp[node][flag];
        }
        int res = flag;
        for (int next : v.get(node)) {
            if (next == pre) {
                continue;
            }
            if (flag == 1) {
                res += Math.min(go(next, node, 0), go(next, node, 1));
            } else {
                res += go(next, node, 1);
            }
        }
        return dp[node][flag] = res;
    }
}