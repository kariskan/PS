import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int[] dp = new int[100001];
		dp[1] = 3;
		dp[2] = 7;
		dp[3] = 17;

		for (int i = 4; i <= n; i++) {
			dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;
		}

		System.out.println(dp[n]);
	}
}