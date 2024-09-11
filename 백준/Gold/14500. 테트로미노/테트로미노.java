import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static int ans;
	static int[][] map = new int[500][500];
	static boolean[][] vis = new boolean[500][500];
	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = true;
				go(new ArrayList<>(List.of(new int[] {i, j})));
				vis[i][j] = false;
			}
		}
		System.out.println(ans);
	}

	static void go(List<int[]> v) {
		if (v.size() == 4) {
			int now = 0;
			for (var a : v) {
				now += map[a[0]][a[1]];
			}
			ans = Math.max(ans, now);
			return;
		}

		for (int i = 0; i < v.size(); i++) {
			for (int k = 0; k < 4; k++) {
				int nx = v.get(i)[0] + dx[k];
				int ny = v.get(i)[1] + dy[k];
				if (range(nx, ny) && !vis[nx][ny]) {
					vis[nx][ny] = true;
					v.add(new int[] {nx, ny});
					go(v);
					v.remove(v.size() - 1);
					vis[nx][ny] = false;
				}
			}
		}
	}

	static boolean range(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}
}