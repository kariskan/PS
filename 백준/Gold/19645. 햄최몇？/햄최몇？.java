import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int[] a = new int[n];
		var st = new StringTokenizer(br.readLine());
		int sum = 0;
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
			sum += a[i];
		}
		boolean[][] dp = new boolean[sum + 1][sum + 1];
		dp[0][0] = true;
		for (int i = 0; i < n; i++) {
			for (int j = sum; j >= 0; j--) {
				for (int k = sum; k >= 0; k--) {
					if (dp[j][k]) {
						continue;
					}
					if (j - a[i] >= 0 && dp[j - a[i]][k]) {
						dp[j][k] = true;
					}
					if (k - a[i] >= 0 && dp[j][k - a[i]]) {
						dp[j][k] = true;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i <= sum; i++) {
			for (int j = 0; j <= sum; j++) {
				if (dp[i][j]) {
					int s = sum - i - j;
					if (s <= i && s <= j) {
						ans = Math.max(ans, s);
					}
				}
			}
		}
		System.out.println(ans);
	}
}