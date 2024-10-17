import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int[] p;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		p = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			p[i] = i;
		}
		List<int[]> v = new ArrayList<>();
		long total = 0;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			total += c;
			v.add(new int[]{a, b, c});
		}
		v.sort(Comparator.comparing(a -> a[2]));
		long ans = 0;
		int cnt = 0;
		for (var i : v) {
			int a = find(i[0]);
			int b = find(i[1]);
			if (a != b) {
				p[b] = a;
				cnt++;
				ans += i[2];
			}
		}
		ans = total - ans;
		if (cnt != n - 1) {
			ans = -1;
		}
		System.out.println(ans);
	}

	static int find(int x) {
		if (p[x] == x) {
			return x;
		}
		return p[x] = find(p[x]);
	}
}