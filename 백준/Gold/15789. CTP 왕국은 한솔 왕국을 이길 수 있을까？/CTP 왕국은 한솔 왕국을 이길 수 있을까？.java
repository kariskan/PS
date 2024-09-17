import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static int[] p = new int[100001];
	static int[] size = new int[100001];
	static boolean[] vis = new boolean[100001];


	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int i = 1; i <= n; i++) {
			p[i] = i;
			size[i] = 1;
		}

		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if (find(a) != find(b)) {
				union(a, b);
			}
		}

		int c, h, k;
		st = new StringTokenizer(br.readLine());
		c = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		var pq = new PriorityQueue<Integer>(Comparator.comparingInt(a -> -a));

		int P = find(c);
		int H = find(h);
		for (int i = 1; i <= n; i++) {
			int now = find(i);
			if (now == P || now == H) {
				continue;
			}
			if (!vis[now]) {
				vis[now] = true;
				pq.offer(size[find(i)]);
			}
		}
		int ans = size[find(c)];
		while (!pq.isEmpty() && k-- > 0) {
			ans += pq.poll();
		}
		System.out.println(ans);
	}

	static void union(int a, int b) {
		a = find(a);
		b = find(b);
		p[b] = a;
		int s = size[a] + size[b];
		size[a] = size[b] = s;
	}

	static int find(int x) {
		if (p[x] == x) {
			return x;
		}
		return p[x] = find(p[x]);
	}
}