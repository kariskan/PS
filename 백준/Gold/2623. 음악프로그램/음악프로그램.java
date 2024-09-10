import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static List<List<Integer>> v = new ArrayList<>();
	static int n, m;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int[] in = new int[1001];
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		for (int i = 0; i <= n; i++) {
			v.add(new ArrayList<>());
		}

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int pre = 0;
			for (int j = 0; j < a; j++) {
				int b = Integer.parseInt(st.nextToken());
				v.get(pre).add(b);
				if (j != 0) {
					in[b]++;
				}
				pre = b;
			}
		}

		Queue<Integer> q = new ArrayDeque<>();
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				q.offer(i);
			}
		}

		StringBuilder sb = new StringBuilder();

		int cnt = 0;
		while (!q.isEmpty()) {
			int now = q.poll();

			sb.append(now).append("\n");
			cnt++;

			for (var i : v.get(now)) {
				if (--in[i] == 0) {
					q.offer(i);
				}
			}
		}

		if (cnt != n) {
			System.out.println(0);
		} else {
			System.out.println(sb);
		}
	}
}