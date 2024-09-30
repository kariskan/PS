import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n, m;
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] a = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			a[i] = Integer.parseInt(st.nextToken());
			a[i] += a[i - 1];
		}
		var sb = new StringBuilder();
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int c = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			sb.append(a[d] - a[c - 1]).append("\n");
		}
		System.out.println(sb);
	}
}