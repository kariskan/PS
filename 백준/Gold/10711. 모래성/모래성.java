import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int[][] board = new int[1000][1000];
	static int n, m;
	static int[] dx = {0, -1, -1, -1, 0, 1, 1, 1};
	static int[] dy = {1, 1, 0, -1, -1, -1, 0, 1};

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			for (int j = 0; j < m; j++) {
				if (s.charAt(j) == '.') {
					continue;
				}
				board[i][j] = s.charAt(j) - '0';
			}
		}

		int ans = 0;
		int[][] vis = new int[1000][1000];
		Queue<int[]> q = new ArrayDeque<>();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) {
					q.offer(new int[] {i, j});
					vis[i][j] = 1;
				}
			}
		}

		while (true) {
			if (q.isEmpty()) {
				break;
			}
			int siz = q.size();
			while (siz-- > 0) {
				var now = q.poll();

				for (int i = 0; i < 8; i++) {
					int nx = now[0] + dx[i];
					int ny = now[1] + dy[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
						if (board[nx][ny] != 0) {
							board[nx][ny]--;
							if (board[nx][ny] == 0) {
								q.offer(new int[] {nx, ny});
							}
						}
						if (board[nx][ny] == 0) {
							vis[nx][ny] = 1;
						}
					}
				}
			}

			ans++;
		}

		System.out.println(ans - 1);
	}
}
