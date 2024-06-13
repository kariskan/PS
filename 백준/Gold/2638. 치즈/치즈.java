import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		int[][] a = new int[100][100];
		int[] dx = {0, 0, 1, -1};
		int[] dy = {1, -1, 0, 0};
		int n, m;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int c = 0;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				a[i][j] = Integer.parseInt(st.nextToken());
				c += a[i][j];
			}
		}
		int ans = 0;
		while (c != 0) {
			Queue<Pair<Integer, Integer>> q = new ArrayDeque<>();
			Queue<Pair<Integer, Integer>> t = new ArrayDeque<>();

			int[][] vis = new int[100][100];

			q.offer(Pair.of(0, 0));
			vis[0][0] = -1;

			while (!q.isEmpty()) {
				Pair<Integer, Integer> p = q.poll();

				for (int i = 0; i < 4; i++) {
					int nx = p.first + dx[i];
					int ny = p.second + dy[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
						if (a[nx][ny] == 0 && vis[nx][ny] != -1) {
							q.offer(Pair.of(nx, ny));
							vis[nx][ny] = -1;
						}
						if (a[nx][ny] == 1) {
							vis[nx][ny]++;
							if (vis[nx][ny] >= 2) {
								t.offer(Pair.of(nx, ny));
							}
						}
					}
				}
			}
			while (!t.isEmpty()) {
				Pair<Integer, Integer> p = t.poll();

				if (a[p.first][p.second] > 0) {
					a[p.first][p.second] = 0;
					c--;
				}
			}
			ans++;
		}
		System.out.println(ans);
	}

	static class Pair<F, S> {
		F first;
		S second;

		public static <F, S> Pair<F, S> of(F first, S second) {
			Pair<F, S> pair = new Pair<>();
			pair.first = first;
			pair.second = second;
			return pair;
		}

		public F getFirst() {
			return first;
		}

		public S getSecond() {
			return second;
		}
	}
}
