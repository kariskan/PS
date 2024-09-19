import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int[] loss = new int[n];
		int[] get = new int[n];

		var st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			loss[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			get[i] = Integer.parseInt(st.nextToken());
		}

		int ans = 0;
		for (int i = 0; i < (1 << n); i++) {
			int health = 100, glad = 0;
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j)) != 0) {
					health -= loss[j];
					glad += get[j];
				}
			}
			if (health <= 0) {
				continue;
			}
			ans = Math.max(ans, glad);
		}

		System.out.println(ans);
	}
}