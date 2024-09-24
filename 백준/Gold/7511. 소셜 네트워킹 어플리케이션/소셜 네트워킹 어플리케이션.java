import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int[] p;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());
		int n, k, m;
		for (int cnt = 1; cnt <= t; cnt++) {
			System.out.println("Scenario " + cnt + ":");
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
					System.out.println(1);
				} else {
					System.out.println(0);
				}
			}
			System.out.println();
		}
	}

	static int find(int x) {
		if (p[x] == -1) {
			return x;
		}
		return p[x] = find(p[x]);
	}
}