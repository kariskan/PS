import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[][] map = new int[3][3];

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int xc = 0, oc = 0;
		for (int i = 0; i < 3; i++) {
			var st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 1) {
					xc++;
				} else if (map[i][j] == 2) {
					oc++;
				}
			}
		}

		int res = go(xc == oc ? 1 : 2);
		if (res == 0) {
			System.out.println("D");
		} else if (res == 1) {
			System.out.println("W");
		} else {
			System.out.println("L");
		}
	}

	static int go(int turn) {
		int op = 2;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (map[i][j] == 0) {
					map[i][j] = turn;
					if (isGameEnd(turn)) {
						// 내가 놓았을 때 게임 끝나면 무조건 이김.
						// 상대방은 무조건 짐
						op = -1;
					}
					op = Math.min(op, go(3 - turn));
					map[i][j] = 0;
				}
			}
		}

		if (op == 1) {
			return -1;
		} else if (op == 0 || op == 2) {
			return 0;
		}
		return 1;
	}

	static boolean isGameEnd(int turn) {
		for (int i = 0; i < 3; i++) {
			if (turn == map[i][0] && map[i][0] == map[i][1] && map[i][1] == map[i][2]) {
				return true;
			}
			if (turn == map[0][i] && map[0][i] == map[1][i] && map[1][i] == map[2][i]) {
				return true;
			}
		}
		if (turn == map[0][0] && map[0][0] == map[1][1] && map[1][1] == map[2][2]) {
			return true;
		}
		if (turn == map[0][2] && map[0][2] == map[1][1] && map[1][1] == map[2][0]) {
			return true;
		}
		return false;
	}
}