import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		var sb = new StringBuilder();
		while (t-- > 0) {
			int n, d;
			var st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			int[][] a = new int[n][n];
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < n; j++) {
					a[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			int[][] ans = new int[n][n];
			int[][] c = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == n / 2 && j == n / 2) {
						ans[i][j] = a[i][j];
					} else if (i == j || (j == n - i - 1) || i == n / 2 || j == n / 2) {
						int x = i - n / 2;
						int y = j - n / 2;
						int len = Math.max(Math.abs(x), Math.abs(y));
						for (int k = 0; k < 8; k++) {
							if (c[k][0] == x / len && c[k][1] == y / len) {
								int next;
								if (d > 0) {
									next = (k + d / 45) % 8;
								} else {
									next = (k + d / 45 + 8) % 8;
								}
								int nx = n / 2 + len * c[next][0];
								int ny = n / 2 + len * c[next][1];
								ans[nx][ny] = a[i][j];
								break;
							}
						}
					} else {
						ans[i][j] = a[i][j];
					}
//					System.out.print(ans[i][j] + " ");
				}
//				System.out.println();
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					sb.append(ans[i][j]).append(" ");
				}
				sb.append("\n");
			}
		}
		System.out.println(sb);
	}
}