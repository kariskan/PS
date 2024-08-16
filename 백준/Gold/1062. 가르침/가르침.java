import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

	static int n, k;
	static int[] a = new int[26];
	static int[] vis = new int[26];
	static String[] v;
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		var st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		v = new String[n];
		for (int i = 0; i < n; i++) {
			v[i] = br.readLine();
			for (int j = 0; j < v[i].length(); j++) {
				a[v[i].charAt(j) - 'a'] = 1;
			}
		}
		for (int i = 0; i < 26; i++) {
			if (i == 0 || i == 'n' - 'a' || i == 't' - 'a' || i == 'i' - 'a' || i == 'c' - 'a') {
				vis[i] = 1;
			}
		}

		if (k < 5) {
			System.out.println(0);
			return;
		}
		go(0, k - 5);
		System.out.println(answer);
	}

	static void go(int idx, int cnt) {
		if (cnt == 0 || idx >= 26) {
			int ans = 0;
			for (int i = 0; i < n; i++) {
				boolean flag = true;
				for (int j = 0; j < v[i].length(); j++) {
					if (vis[v[i].charAt(j) - 'a'] != 1) {
						flag = false;
						break;
					}
				}
				if (flag) {
					ans++;
				}
				answer = Math.max(answer, ans);
			}
			return;
		}
		if (a[idx] == 0 || vis[idx] == 1) {
			go(idx + 1, cnt);
		} else {
			go(idx + 1, cnt);
			vis[idx] = 1;
			go(idx + 1, cnt - 1);
			vis[idx] = 0;
		}
	}
}