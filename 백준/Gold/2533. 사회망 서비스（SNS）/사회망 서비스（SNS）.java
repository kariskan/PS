import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static int[][] dp;
	static List<List<Integer>> v = new ArrayList<>();

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());

		dp = new int[n + 1][2];
		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
		}
		for (int i = 0; i < n - 1; i++) {
			var st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			v.get(a).add(b);
			v.get(b).add(a);
		}

		System.out.println(Math.min(go(1, 0, 0), go(1, 0, 1)));
	}

	static int go(int node, int pre, int flag) {
		if (dp[node][flag] != 0) {
			return dp[node][flag];
		}

		int res = flag;
		for (var c : v.get(node)) {
			if (c == pre) {
				continue;
			}
			if (flag == 0) {
				res += go(c, node, 1);
			} else {
				res += Math.min(go(c, node, 0), go(c, node, 1));
			}
		}
		return dp[node][flag] = res;
	}
}