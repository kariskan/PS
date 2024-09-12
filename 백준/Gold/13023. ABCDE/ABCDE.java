import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static boolean[] vis = new boolean[2000];
	static List<List<Integer>> v = new ArrayList<>();
	static int ans;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		var st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			v.add(new ArrayList<>());
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			v.get(a).add(b);
			v.get(b).add(a);
		}

		// 0-1-2-3

		//   2
		//   |
		// 1-7--3-5
		//   | /
		// 0-4/
		// |
		// 6
		for (int i = 0; i < n; i++) {
			vis[i] = true;
			go(i, -1, 1);
			vis[i] = false;
		}
		System.out.println(ans);
	}

	static void go(int now, int pre, int cnt) {
		if (cnt >= 5) {
			ans = 1;
			return;
		}
		for (var i : v.get(now)) {
			if (i != pre && !vis[i]) {
				vis[i] = true;
				go(i, now, cnt + 1);
				if (ans == 1) {
					return;
				}
				vis[i] = false;
			}
		}
	}
}