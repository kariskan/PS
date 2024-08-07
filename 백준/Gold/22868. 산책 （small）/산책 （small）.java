import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int n, m, s, e;
	static List<List<Integer>> v;
	static int[] vis = new int[10001];
	static int[] pre = new int[10001];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		v = new ArrayList<>(n + 1);

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

		st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= n; i++) {
			v.get(i).sort(Comparator.naturalOrder());
		}

		Queue<Integer> q = new ArrayDeque<>();
		q.offer(s);
		vis[s] = 1;

		while (!q.isEmpty()) {
			int p = q.poll();

			for (int next : v.get(p)) {
				if (vis[next] != 0) {
					continue;
				}
				if (next == e) {
					int nowVis = vis[p];
					vis = new int[10001];
					q.clear();
					vis[next] = nowVis + 1;
					int now = p;
					while (now != s) {
						vis[now] = -1;
						now = pre[now];
					}                
    				q.offer(next);
                    break;
				} else {
					vis[next] = vis[p] + 1;
				}
				pre[next] = p;
				q.offer(next);
			}
		}

		System.out.println(vis[s] - 1);
	}
}
