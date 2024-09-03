import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int n, q;
	static int[] dx = {0, 0, 1, -1};
	static int[] dy = {1, -1, 0, 0};

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		q = Integer.parseInt(st.nextToken());

		int[][] board = new int[1 << n][1 << n];
		for (int i = 0; i < (1 << n); i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < (1 << n); j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < q; i++) {
			int l = Integer.parseInt(st.nextToken());
			go(board, l);
			fire(board);
		}

		int total = 0, max = 0;
		int[][] vis = new int[1 << n][1 << n];
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < (1 << n); j++) {
				total += board[i][j];
				if (board[i][j] != 0) {
					int temp = 0;
					Queue<int[]> q = new ArrayDeque<>();
					q.offer(new int[] {i, j});
					vis[i][j] = 1;
					while (!q.isEmpty()) {
						var now = q.poll();
						temp++;

						for (int k = 0; k < 4; k++) {
							int nx = now[0] + dx[k];
							int ny = now[1] + dy[k];
							if (nx >= 0 && nx < (1 << n) && ny >= 0 && ny < (1 << n) && board[nx][ny] != 0
								&& vis[nx][ny] == 0) {
								q.offer(new int[] {nx, ny});
								vis[nx][ny] = 1;
							}
						}
					}
					max = Math.max(temp, max);
				}
			}
		}
		System.out.println(total);
		System.out.println(max);
	}

	static void go(int[][] board, int l) {
		for (int i = 0; i < (1 << n); i += (1 << l)) {
			for (int j = 0; j < (1 << n); j += (1 << l)) {
				rotate(board, i, j, l);
			}
		}
	}

	static void rotate(int[][] board, int sx, int sy, int l) {
		int[][] newBoard = new int[1 << l][1 << l];
		for (int i = 0; i < (1 << l); i++) {
			for (int j = 0; j < (1 << l); j++) {
				newBoard[i][j] = board[sx + i][sy + j];
			}
		}
		int[][] newBoard2 = new int[1 << l][1 << l];
		for (int i = 0; i < (1 << l); i++) {
			for (int j = 0; j < (1 << l); j++) {
				newBoard2[i][j] = newBoard[(1 << l) - j - 1][i];
			}
		}

		for (int i = 0; i < (1 << l); i++) {
			for (int j = 0; j < (1 << l); j++) {
				board[sx + i][sy + j] = newBoard2[i][j];
			}
		}
	}

	static void fire(int[][] board) {
		List<int[]> list = new ArrayList<>();
		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j < (1 << n); j++) {
				int exist = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (!(nx >= 0 && nx < (1 << n) && ny >= 0 && ny < (1 << n)) || board[nx][ny] == 0) {
						exist++;
					}
				}
				if (exist >= 2) {
					list.add(new int[] {i, j});
				}
			}
		}
		for (int[] i : list) {
			if (board[i[0]][i[1]] != 0) {
				board[i[0]][i[1]]--;
			}
		}
	}
}