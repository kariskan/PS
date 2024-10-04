import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int n, h, d;
	static int sx = 0, sy = 0, ex = 0, ey = 0;
	static int ans = Integer.MAX_VALUE;
	static List<int[]> u = new ArrayList<>();
	static boolean[] vis;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		vis = new boolean[10];

		for (int i = 0; i < n; i++) {
			String s = br.readLine();
			for (int j = 0; j < n; j++) {
				if (s.charAt(j) == 'S') {
					sx = i;
					sy = j;
				} else if (s.charAt(j) == 'E') {
					ex = i;
					ey = j;
				} else if (s.charAt(j) == 'U') {
					u.add(new int[]{i, j});
				}
			}
		}
		go(sx, sy, h, 0, 0);
		if (ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
		}
	}

	static void go(int x, int y, int nowH, int nowD, int cost) {
//		System.out.println(x + " " + y + " " + nowH + " " + nowD + " " + cost);
		if (dis(x, y, ex, ey) <= nowH + nowD) {
			ans = Math.min(ans, cost + dis(x, y, ex, ey));
			return;
		}
		for (int i = 0; i < u.size(); i++) {
			if (!vis[i]) {
				int dis = dis(x, y, u.get(i)[0], u.get(i)[1]);
				if (dis > nowH + nowD) {
					continue;
				}
				vis[i] = true;
				go(u.get(i)[0], u.get(i)[1], Math.min(nowH, nowH + nowD - dis), d, cost + dis);
				vis[i] = false;
			}
		}
	}

	static int dis(int sourceX, int sourceY, int targetX, int targetY) {
		return Math.abs(sourceX - targetX) + Math.abs(sourceY - targetY);
	}
}