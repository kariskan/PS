import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static List<List<int[]>> v = new ArrayList<>();
	static int ans, node;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		for (int i = 0; i <= 10000; i++) {
			v.add(new ArrayList<>());
		}
		while (true) {
			String s = br.readLine();
			if (s == null || s.isEmpty()) {
				break;
			}

			var st = new StringTokenizer(s);
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			v.get(a).add(new int[]{b, c});
			v.get(b).add(new int[]{a, c});
		}
		go(1, 0, 0);
		go(node, 0, 0);
		System.out.println(ans);
	}

	static void go(int now, int pre, int cost) {
		if (ans < cost) {
			ans = cost;
			node = now;
		}
		for (var c : v.get(now)) {
			if (c[0] == pre) {
				continue;
			}
			go(c[0], now, cost + c[1]);
		}
	}
}