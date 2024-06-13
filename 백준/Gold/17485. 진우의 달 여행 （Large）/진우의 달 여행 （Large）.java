import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		int[][] a = new int[1001][1001];
		int[][][] dp = new int[1001][1002][3];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n, m;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= m; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
				if (i == 1) {
					dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = a[i][j];
				}
			}
			dp[i][1][2] = dp[i][m][0] = Integer.MAX_VALUE;
		}
		int ans = Integer.MAX_VALUE;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j < m) {
					dp[i][j][0] = Math.min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + a[i][j];
				}
				dp[i][j][1] = Math.min(dp[i - 1][j][0], dp[i - 1][j][2]) + a[i][j];
				if (j > 1) {
					dp[i][j][2] = Math.min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + a[i][j];
				}
				if (i == n) {
					ans = Math.min(ans, Math.min(dp[i][j][0], Math.min(dp[i][j][1], dp[i][j][2])));
				}
			}
		}
		System.out.println(ans);
	}
}
