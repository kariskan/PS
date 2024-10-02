import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		long[][] a = new long[n + 1][n + 1];
		long[][] ans = new long[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		/**
		 * 0 0 0 0 0
		 * 0 0 0 0 0
		 * 0 1 0 0 0
		 * 0 1 0 6 0
		 * 0 0 0 0 0
		 */

		/**
		 * -8 -17 -26 -18 -9
		 * -9 -29 -47 -38 -18
		 * -10 -38 -62 -52 -24
		 * -2 -21 -36 -34 -15
		 * -1 -9 -15 -14 -6
		 *
		 * -8 -17 -26 -18 -9
		 * -9 -29 -47 -38 -18
		 * -9 -37 -61 -52 -24
		 * -1 -20 -35 -34 -15
		 * 0 -8 -14 -14 -6
		 *
		 * -8 -17 -26 -18 -9
		 * -8 -28 -46 -38 -18
		 * -8 -36 -60 -52 -24
		 * 0 -19 -34 -34 -15
		 * 0 -8 -14 -14 -6
		 *
		 * -8 -17 -26 -18 -9
		 * -8 -28 -46 -38 -18
		 * -8 -36 -54 -46 -18
		 * 0 -19 -28 -28 -9
		 * 0 -8 -8 -8 0
		 *
		 * 0 0 0 0 0
		 * 0 8 9 9 0
		 * 0 1 11 9 0
		 * 0 1 8 6 0
		 * 0 0 0 0 0
		 *
		 * 0 0 0 0 0 0 0
		 * 0 -2 0 0 2 0 0
		 * 0 0 0 0 0 0 0
		 * 0 0 0 0 0 0 0
		 * 0 2 0 0 -2 0 0
		 * 0 0 0 0 0 0 0
		 */

		for (int j = 0; j < n; j++) {
			for (int i = n; i >= 1; i--) {
				a[i][j] = a[i][j] - a[i - 1][j];
			}
		}
//		for (int i = 0; i <= n; i++) {
//			System.out.println(Arrays.toString(a[i]));
//		}
		for (int i = 0; i < n; i++) {
			for (int j = n; j >= 1; j--) {
				a[i][j] = a[i][j] - a[i][j - 1];
			}
		}
//		System.out.println();
//		for (int i = 0; i <= n; i++) {
//			System.out.println(Arrays.toString(a[i]));
//		}

		/**
		 *  -8 -17 -26 -18  -9
		 *  -9 -29 -47 -38 -18
		 * -10 -38 -62 -52 -24
		 *  -2 -21 -36 -34 -15
		 *  -1  -9 -15 -14  -6
		 *
		 *  -8 -17 -26 -18  -9
		 *  -1 -12 -21 -20  -9
		 *  -1  -9 -15 -14  -6
		 *   8  17  26  18   9
		 *   1  12  21  20   9
		 *   1   9  15  14   6
		 *
		 *  -8  -9  -9   8   9
		 *
		 */
//		System.out.println();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) {
					continue;
				}
				int len = m / 2;
				long c = a[i][j];

				ans[i + len][j + len] -= c;
				a[i][j] -= c;
				a[i][j + m] += c;
				a[i + m][j] += c;
				a[i + m][j + m] -= c;
			}
		}
		var sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sb.append(ans[i][j]).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}