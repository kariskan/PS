import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static int[][] v = new int[251][251];
	static int[][] inp = new int[251][251];

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					inp[i][j] = 1;
					continue;
				}
				v[i][j] = 1000000;
			}
		}

		for (int i = 0; i < m; i++) {
			int a, b, c;
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			inp[a][b] = inp[b][a] = 1;
			v[a][b] = v[b][a] = 0;
			if (c == 0) {
				v[b][a] = 1;
			}
		}

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (i == j) {
						continue;
					}
					if (inp[i][k] == 1 && inp[k][j] == 1) {
						inp[i][j] = 1;
						if (v[i][j] > v[i][k] + v[k][j]) {
							v[i][j] = v[i][k] + v[k][j];
						}
					}
				}
			}
		}

		int q = Integer.parseInt(br.readLine());
		for (int i = 1; i <= q; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			System.out.println(v[a][b]);
		}
	}
}