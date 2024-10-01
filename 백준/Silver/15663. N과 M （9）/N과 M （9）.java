import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static int[] a;
	static boolean[] vis;
	static int[] ans;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		a = new int[n];
		ans = new int[m];
		vis = new boolean[n];
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(a);
		go(0);
		System.out.println(sb);
	}

	static void go(int cnt) {
		if (cnt == m) {
			for (int i = 0; i < m; i++) {
				sb.append(ans[i]).append(" ");
			}
			sb.append("\n");
			return;
		}

		int last = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] != last && !vis[i]) {
				vis[i] = true;
				ans[cnt] = a[i];
				last = a[i];
				go(cnt + 1);
				vis[i] = false;
			}
		}
	}

//	public static void main(String[] args) throws Exception {
//		var br = new BufferedReader(new InputStreamReader(System.in));
//		int n, m;
//		var st = new StringTokenizer(br.readLine());
//		n = Integer.parseInt(st.nextToken());
//		m = Integer.parseInt(st.nextToken());
//		int[] a = new int[n + 1];
//		int[][] dp = new int[n + 1][m + 3];
//		for (int i = 1; i < n + 1; i++) {
//			a[i] = Integer.parseInt(br.readLine());
//		}
//
//		for (int i = 1; i <= n; i++) {
//			for (int j = 0; j <= m; j++) {
//				if (j == 0) {
//					dp[i][j] = Math.max(dp[i - 1][j + 1], dp[i - 1][j]);
//				} else {
//					dp[i][j] = Math.max(dp[i - 1][j + 1], dp[i - 1][j - 1] + a[i]);
//				}
//			}
//		}
//
//		System.out.println(dp[n][0]);
//	}
}