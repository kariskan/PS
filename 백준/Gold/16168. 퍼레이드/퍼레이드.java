import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static List<List<Integer>> v = new ArrayList<>();
	static int[][] e;
	static String ans = "NO";

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
		}
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			v.get(a).add(b);
			v.get(b).add(a);
		}

		e = new int[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			go(i, 0, 0, i);
		}

		System.out.println(ans);
	}

	static void go(int node, int pre, int cnt, int ver) {
		if (cnt == m) {
			ans = "YES";
			return;
		}
		for (var i : v.get(node)) {
			if (e[node][i] == ver || e[i][node] == ver || i == pre) {
				continue;
			}
			e[node][i] = e[i][node] = ver;
			go(i, node, cnt + 1, ver);
		}
	}
}