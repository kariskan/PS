import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n;
	static int[] a = new int[5000];
	static int[] dp = new int[5000];
	static boolean[][] pal = new boolean[5000][5000];

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		var st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		for (int i = 0; i < n; i++) {
			int l = i, r = i + 1;
			while (l >= 0 && r < n && a[l] == a[r]) {
				pal[l][r] = true;
				l--;
				r++;
			}
			dp[i] = -1;
		}
		int ans = go(n - 1);
		if (ans == 0) {
			ans = -1;
		}
		System.out.println(ans);
	}

	static int go(int idx) {
		if (dp[idx] != -1) {
			return dp[idx];
		}
		int res = pal[0][idx] ? 1 : 0;
		for (int i = 1; i < idx; i += 2) {
			if (pal[i + 1][idx]) {
				int in = go(i);
				if (in == 0) {
					continue;
				}
				res = Math.max(res, in + 1);
			}
		}
		return dp[idx] = res;
	}
}