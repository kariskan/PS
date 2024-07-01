import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {

	static char[][][] board = new char[9][8][8];
	static int[][][] vis = new int[100][8][8];
	static int[] dx = {0, 0, -1, -1, -1, 0, 1, 1, 1};
	static int[] dy = {0, 1, 1, 0, -1, -1, -1, 0, 1};

	public static void main(String[] args) throws Exception {
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

		for (int i = 0; i <= 8; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 8; k++) {
					board[i][j][k] = '.';
				}
			}
		}

		for (int i = 0; i < 8; i++) {
			String s = bufferedReader.readLine();
			for (int j = 0; j < 8; j++) {
				board[0][i][j] = s.charAt(j);
			}
		}

		for (int k = 1; k <= 8; k++) {
			for (int i = k; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					board[k][i][j] = board[k - 1][i - 1][j];
				}
			}
		}

		Queue<Pair<Integer, Pair<Integer, Integer>>> q = new PriorityQueue<>((p1, p2) -> p2.first - p1.first);
		q.offer(Pair.of(0, Pair.of(7, 0)));
		vis[0][7][0] = 1;

		while (!q.isEmpty()) {
			Pair<Integer, Pair<Integer, Integer>> poll = q.poll();
			int time = poll.first;
			int x = poll.second.first;
			int y = poll.second.second;

			if (x == 0 && y == 7) {
				System.out.println(1);
				return;
			}

			for (int i = 0; i < 9; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nt = Math.min(time + 1, 8);
				if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8 && board[time][nx][ny] == '.' && board[nt][nx][ny] == '.'
					&& vis[nt][nx][ny] == 0) {
					q.offer(Pair.of(nt, Pair.of(nx, ny)));
					vis[nt][nx][ny] = vis[time][x][y] + 1;
				}
			}
		}

		System.out.println(0);
	}

	static class Pair<F, S> {
		public F first;
		public S second;

		private Pair(F first, S second) {
			this.first = first;
			this.second = second;
		}

		public static <F, S> Pair<F, S> of(F first, S second) {
			return new Pair<>(first, second);
		}
	}
}