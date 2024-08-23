import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		int[][] board = new int[n][n];
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int s, x, y;
		st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());

		Queue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> board[a[0]][a[1]]));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != 0) {
					q.offer(new int[] {i, j});
				}
			}
		}

		int[] dx = {0, 0, 1, -1};
		int[] dy = {1, -1, 0, 0};
		while (s-- > 0) {

			int size = q.size();
			Queue<int[]> t = new PriorityQueue<>(Comparator.comparingInt(a -> board[a[0]][a[1]]));
			for (int i = 0; i < size; i++) {
				int[] c = q.poll();

				for (int k = 0; k < 4; k++) {
					int nx = c[0] + dx[k];
					int ny = c[1] + dy[k];
					if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 0) {
						t.offer(new int[] {nx, ny});
						board[nx][ny] = board[c[0]][c[1]];
					}
				}
			}

			while (!t.isEmpty()) {
				q.offer(t.poll());
			}
		}

		System.out.println(board[x - 1][y - 1]);
	}
}