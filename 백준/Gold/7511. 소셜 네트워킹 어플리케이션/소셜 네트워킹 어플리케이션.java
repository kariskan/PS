import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[] p;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());
		int n, k, m;
		var sb = new StringBuilder();

		for (int cnt = 1; cnt <= t; cnt++) {
			sb.append("Scenario ").append(cnt).append(":").append("\n");
			n = Integer.parseInt(br.readLine());
			k = Integer.parseInt(br.readLine());
			p = new int[n + 1];
			for (int i = 0; i < n; i++) {
				p[i] = -1;
			}
			for (int i = 0; i < k; i++) {
				var st = new StringTokenizer(br.readLine());
				int a = find(Integer.parseInt(st.nextToken()));
				int b = find(Integer.parseInt(st.nextToken()));
				if (a != b) {
					p[b] = a;
				}
			}
			m = Integer.parseInt(br.readLine());
			for (int i = 0; i < m; i++) {
				var st = new StringTokenizer(br.readLine());
				int a = find(Integer.parseInt(st.nextToken()));
				int b = find(Integer.parseInt(st.nextToken()));
				if (a == b) {
					sb.append("1\n");
				} else {
					sb.append("0\n");
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}

	static int find(int x) {
		if (p[x] == -1) {
			return x;
		}
		return p[x] = find(p[x]);
	}
}