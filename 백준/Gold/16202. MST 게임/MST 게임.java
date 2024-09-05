import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int[] p = new int[10001];

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		var bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n, m, k;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		List<int[]> v = new ArrayList<>();
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a, b;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			v.add(new int[] {i + 1, a, b});
		}
		while (k-- > 0) {
			int ans = 0, cnt = 0;
			for (int i = 1; i <= n; i++) {
				p[i] = i;
			}
			for (var i : v) {
				if (find(i[1]) != find(i[2])) {
					union(i[1], i[2]);
					ans += i[0];
					cnt++;
				}
			}
			if (cnt == n - 1) {
				bw.write(ans + " ");
			} else {
				bw.write("0 ");
			}
			v.remove(0);
		}
		bw.flush();
		bw.close();
	}

	static int find(int x) {
		if (p[x] == x) {
			return x;
		}
		return p[x] = find(p[x]);
	}

	static void union(int a, int b) {
		p[find(a)] = find(b);
	}
}