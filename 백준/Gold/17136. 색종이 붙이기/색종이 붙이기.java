import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[][] map = new int[10][10];
	static int[] cnt = {0, 5, 5, 5, 5, 5};
	static int ans = -1;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		for (int i = 0; i < 10; i++) {
			var st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 10; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		go(0, 0, 0);
		System.out.println(ans);
	}

	static void go(int x, int y, int num) {
		if (x == 10) {
			if (ans == -1 || ans > num) {
				ans = num;
			}
			return;
		}
		if (y == 10) {
			go(x + 1, 0, num);
			return;
		}
		if (map[x][y] == 0) {
			go(x, y + 1, num);
			return;
		}
		for (int k = 5; k >= 1; k--) {
			if (cnt[k] == 0 || x + k > 10 || y + k > 10) {
				continue;
			}
			boolean flag = true;
			for (int i = x; i < x + k; i++) {
				for (int j = y; j < y + k; j++) {
					if (map[i][j] == 0) {
						flag = false;
						break;
					}
				}
			}
			if (!flag) {
				continue;
			}
			for (int i = x; i < x + k; i++) {
				for (int j = y; j < y + k; j++) {
					map[i][j] = 0;
				}
			}
			cnt[k]--;
			go(x, y + 1, num + 1);
			cnt[k]++;
			for (int i = x; i < x + k; i++) {
				for (int j = y; j < y + k; j++) {
					map[i][j] = 1;
				}
			}
		}
	}
}