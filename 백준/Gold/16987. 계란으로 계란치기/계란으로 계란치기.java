import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n, ans;
	static int[][] info = new int[8][2];

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());

		for (int i = 0; i < n; i++) {
			var st = new StringTokenizer(br.readLine());
			info[i][0] = Integer.parseInt(st.nextToken());
			info[i][1] = Integer.parseInt(st.nextToken());
		}
		go(0);
		System.out.println(ans);
	}

	static void go(int idx) {
		if (idx == n) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (info[i][0] <= 0) {
					cnt++;
				}
			}
			ans = Math.max(ans, cnt);
			return;
		}
		if (info[idx][0] <= 0) {
			go(idx + 1);
			return;
		}

		boolean flag = false;
		for (int i = 0; i < n; i++) {
			if (i == idx || info[i][0] <= 0) {
				continue;
			}
			flag = true;
			info[i][0] -= info[idx][1];
			info[idx][0] -= info[i][1];
			go(idx + 1);
			info[i][0] += info[idx][1];
			info[idx][0] += info[i][1];
		}
		if (!flag) {
			go(idx + 1);
		}
	}
}