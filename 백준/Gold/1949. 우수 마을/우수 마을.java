import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static int[] w;
	static List<List<Integer>> v;
	static int[][] dp;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		var st = new StringTokenizer(br.readLine());
		w = new int[n + 1];
		dp = new int[n + 1][2];
		v = new ArrayList<>();
		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
			dp[i][0]=dp[i][1]=-1;
		}
		for (int i = 1; i <= n; i++) {
			w[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			v.get(a).add(b);
			v.get(b).add(a);
		}
		System.out.println(Math.max(go(1, 0, 0), go(1, 0, 1)));
//		for (int i = 1; i <= n; i++) {
//			System.out.println(Arrays.toString(dp[i]));
//		}
	}

	static int go(int node, int pre, int flag) {
		if (dp[node][flag] != -1) {
			return dp[node][flag];
		}
		int res = 0;

//		1-2-3-4-5
//		  |
//		  6-7
		for (var c : v.get(node)) {
			if (c == pre) {
				continue;
			}
			if (flag == 1) {
				res += go(c, node, 0);
			} else {
				res += Math.max(go(c, node, 0), go(c, node, 1));
			}
		}
		return dp[node][flag] = res + (flag == 1 ? w[node] : 0);
	}
}