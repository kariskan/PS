import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

	static int[] a = new int[16];
	static int n;
	static int ans = 0;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		go(1);
		System.out.println(ans);
	}

	static void go(int idx) {
		if (idx > n) {
			ans++;
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (valid(idx, i)) {
				a[idx] = i;
				go(idx + 1);
				a[idx] = 0;
			}
		}
	}

	static boolean valid(int idx, int j) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == j || (a[i] != 0 && Math.abs(idx - i) == Math.abs(j - a[i]))) {
				return false;
			}
		}
		return true;
	}
}
