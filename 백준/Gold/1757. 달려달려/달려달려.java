import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[] a = new int[n + 1];
		int[][][] dp = new int[n + 1][m + 3][2];
		for (int i = 1; i < n + 1; i++) {
			a[i] = Integer.parseInt(br.readLine());
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= Math.min(i, m); j++) {
				if (j == 0) {
					dp[i][j][0] = Math.max(dp[i - 1][1][0], Math.max(dp[i - 1][0][0], dp[i - 1][1][1]));
				} else {
					if (j != m) {
						dp[i][j][0] = Math.max(dp[i - 1][j + 1][1], dp[i - 1][j + 1][0]);
					}
					if (j == 1) {
						dp[i][j][1] = dp[i - 1][j - 1][0] + a[i];
					}
					dp[i][j][1] = Math.max(dp[i][j][1], dp[i - 1][j - 1][1] + a[i]);
				}
			}
		}

		System.out.println(dp[n][0][0]);
	}
}