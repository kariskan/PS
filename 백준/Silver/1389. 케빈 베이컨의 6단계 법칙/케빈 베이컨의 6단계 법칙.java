import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int[][] a = new int[101][101];
		int n, m;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int i = 0; i < m; i++) {
			int x, y;
			st = new StringTokenizer(br.readLine());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			a[x][y] = a[y][x] = 1;
		}

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i == j) {
						continue;
					}
					if (a[i][k] > 0 && a[k][j] > 0 && (a[i][j] == 0 || a[i][j] > a[i][k] + a[k][j])) {
						a[i][j] = a[i][k] + a[k][j];
					}
				}
			}
		}

		int ans = 0, ansSum = Integer.MAX_VALUE;
		for (int i = 1; i <= n; i++) {
			int s = 0;
			for (int j = 1; j <= n; j++) {
				s += a[i][j];
			}
			if (s < ansSum) {
				ans = i;
				ansSum = s;
			}
		}
		System.out.println(ans);
	}
}
