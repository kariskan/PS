import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());

		int[] dp = new int[100001];

		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + 1;
			dp[i] = Math.min(dp[i], dp[i - 2] + 1);
			if (i >= 5) {
				dp[i] = Math.min(dp[i], dp[i - 5] + 1);
			}
			if (i >= 7) {
				dp[i] = Math.min(dp[i], dp[i - 7] + 1);
			}
		}

		System.out.println(dp[n]);
	}
}