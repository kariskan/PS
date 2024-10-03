import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] a = new int[n + 1][m + 1];
		int[][] dp = new int[n + 1][m + 1];
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= m; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
				if (a[i][j] != 0) {
					continue;
				}
				dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
				ans = Math.max(ans, dp[i][j]);
			}
		}
		System.out.println(ans);
	}
}