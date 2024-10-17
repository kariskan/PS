import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());
		int n = Integer.parseInt(br.readLine());
		int[][] a = new int[n + 1][2];
		int[] dp = new int[t + 1];
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			var st = new StringTokenizer(br.readLine());
			a[i][0] = Integer.parseInt(st.nextToken());
			a[i][1] = Integer.parseInt(st.nextToken());
			for (int j = t - a[i][0]; j >= 0; j--) {
				if (dp[j] == 0) {
					continue;
				}
				for (int k = 1; k <= a[i][1]; k++) {
					int now = j + a[i][0] * k;
					if (now > t) {
						break;
					}
					dp[now] += dp[j];
				}
			}
		}
		System.out.println(dp[t]);
	}
}