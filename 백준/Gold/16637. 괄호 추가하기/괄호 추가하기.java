import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

	static int n;
	static String s;
	static long ans = Integer.MIN_VALUE;
	static boolean[] vis = new boolean[20];

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		s = br.readLine();

		go(0);
		System.out.println(ans);
	}

	static void go(int idx) {
		if (idx > n - 3) {
			ans = Math.max(ans, cal());
			return;
		}
		go(idx + 2);
		vis[idx] = true;
		go(idx + 4);
		vis[idx] = false;
	}

	static long cal() {
		List<Long> st = new ArrayList<>();
		List<Character> st2 = new ArrayList<>();
		for (int i = 0; i < s.length(); i++) {
			if (i % 2 == 0) {
				if (!vis[i]) {
					st.add((long) (s.charAt(i) - '0'));
				} else {
					if (s.charAt(i + 1) == '+') {
						st.add((long) (s.charAt(i) - '0') + (long) (s.charAt(i + 2) - '0'));
					} else if (s.charAt(i + 1) == '-') {
						st.add((long) (s.charAt(i) - '0') - (long) (s.charAt(i + 2) - '0'));
					} else {
						st.add((long) (s.charAt(i) - '0') * (long) (s.charAt(i + 2) - '0'));
					}
					i += 2;
				}
			} else {
				st2.add(s.charAt(i));
			}
		}
		long ret = st.get(0);
		for (int i = 0; i < st2.size(); i++) {
			if (st2.get(i) == '+') {
				ret += st.get(i + 1);
			} else if (st2.get(i) == '-') {
				ret -= st.get(i + 1);
			} else {
				ret *= st.get(i + 1);
			}
		}
		return ret;
	}
}