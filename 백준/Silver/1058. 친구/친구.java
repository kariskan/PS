import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int[][] a = new int[n][n];
		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			for (int j = 0; j < n; j++) {
				if (s.charAt(j) == 'Y') {
					a[i][j] = 1;
				}
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j) {
						continue;
					}
					if (a[i][k] > 0 && a[k][j] > 0) {
						if (a[i][j] == 0 || a[i][j] > a[i][k] + a[k][j]) {
							a[i][j] = a[i][k] + a[k][j];
						}
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				if (a[i][j] <= 2 && a[i][j] > 0) {
					cnt++;
				}
			}
			ans = Math.max(ans, cnt);
		}
		System.out.println(ans);
	}
}