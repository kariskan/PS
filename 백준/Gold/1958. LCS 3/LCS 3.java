import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	static String s1, s2, s3;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		s1 = br.readLine();
		s2 = br.readLine();
		s3 = br.readLine();

		int[][][] dp = new int[101][101][101];
		int max = 0;
		for (int i = 1; i <= s1.length(); i++) {
			for (int j = 1; j <= s2.length(); j++) {
				for (int k = 1; k <= s3.length(); k++) {
					dp[i][j][k] = maxV(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1], dp[i - 1][j - 1][k],
						dp[i - 1][j][k - 1], dp[i][j - 1][k - 1]);
					if (s1.charAt(i - 1) == s2.charAt(j - 1) && s2.charAt(j - 1) == s3.charAt(k - 1)) {
						dp[i][j][k] = Math.max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
					}
					max = Math.max(max, dp[i][j][k]);
				}
			}
		}

		System.out.println(max);
	}

	static int maxV(int... values) {
		int max = 0;
		for (int value : values) {
			max = Math.max(max, value);
		}
		return max;
	}
}
