import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int n, m;
	static boolean[] check = new boolean[10];
	static int[] vis = new int[10];
	static int ans;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		if (m != 0) {
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < m; i++) {
				check[Integer.parseInt(st.nextToken())] = true;
			}
		}
		go(0);
		System.out.println(ans);
	}

	static void go(int len) {
		if (len == n) {
			if (isVis()) {
				ans++;
			}
			return;
		}
		for (int i = 0; i < 10; i++) {
			vis[i]++;
			go(len + 1);
			vis[i]--;
		}
	}

	static boolean isVis() {
		for (int i = 0; i < 10; i++) {
			if (check[i] && vis[i] == 0) {
				return false;
			}
		}
		return true;
	}
}