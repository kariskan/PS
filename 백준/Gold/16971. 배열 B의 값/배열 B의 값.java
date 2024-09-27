import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		// 3 + 2 + 2 + 1
		// 9 + 8 + 8 + 7
		// - 3 - 2 - 2 - 1 + 9 + 8 + 8 + 7

		int[] row = new int[n];
		int[] col = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1
					&& j == m - 1)) {
					row[i] += a[i][j];
				} else if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
					row[i] += a[i][j] * 2;
				} else {
					row[i] += a[i][j] * 4;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if ((i == 0 && j == 0) || (i == 0 && j == n - 1) || (i == m - 1 && j == 0) || (i == m - 1
					&& j == n - 1)) {
					col[i] += a[j][i];
				} else if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
					col[i] += a[j][i] * 2;
				} else {
					col[i] += a[j][i] * 4;
				}
			}
			if (i == 0 || i == m - 1) {
				ans += col[i];
			} else {
				ans += col[i];
			}
		}
		int total = ans;
		for (int i = 1; i < n - 1; i++) {
			ans = Math.max(ans, total + row[0] - row[i] / 2);
			ans = Math.max(ans, total + row[n - 1] - row[i] / 2);
		}
		for (int i = 1; i < m - 1; i++) {
			ans = Math.max(ans, total + col[0] - col[i] / 2);
			ans = Math.max(ans, total + col[m - 1] - col[i] / 2);
		}
		System.out.println(ans);
	}
}