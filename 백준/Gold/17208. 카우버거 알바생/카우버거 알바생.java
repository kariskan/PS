import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, m, k;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		int[][] dp = new int[m + 1][k + 1];
		int[][] inp = new int[n + 1][2];
		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			inp[i][0] = Integer.parseInt(st.nextToken());
			inp[i][1] = Integer.parseInt(st.nextToken());
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = m; j >= inp[i][0]; j--) {
				for (int l = k; l >= inp[i][1]; l--) {
					dp[j][l] = Math.max(dp[j][l], dp[j - inp[i][0]][l - inp[i][1]] + 1);
					ans = Math.max(ans, dp[j][l]);
				}
			}
		}
		System.out.println(ans);
	}
}