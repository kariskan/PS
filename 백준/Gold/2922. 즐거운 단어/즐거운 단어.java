import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	static char[] s;
	static long ans;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		String inp = br.readLine();
		s = new char[inp.length()];
		for (int i = 0; i < inp.length(); i++) {
			s[i] = inp.charAt(i);
		}
		go(0);
		System.out.println(ans);
	}

	static void go(int idx) {
		if (idx == s.length) {
			if (!check()) {
				return;
			}
			long cnt = 1;
			for (int i = 0; i < s.length; i++) {
				if (s[i] == '*') {
					cnt *= 20;
				} else if (s[i] == '+') {
					cnt *= 5;
				}
			}
			// for(int i=0;i<s.length;i++){
			// 	System.out.print(s[i]);
			// }
			// System.out.println();
			// // 5 + 5*27 + 5 + 5*27 + 5*5 + 27*5 + 27*5 + 5*5 + 5*5
			ans += cnt;
			return;
		}

		if (s[idx] == '_') {
			s[idx] = 'L';
			go(idx + 1);

			// 자음
			s[idx] = '*';
			go(idx + 1);

			// 모음
			s[idx] = '+';
			go(idx + 1);
			s[idx] = '_';
		} else {
			go(idx + 1);
		}
	}

	static boolean check() {
		boolean l = false;
		for (int i = 0; i < s.length; i++) {
			if (s[i] == 'L') {
				l = true;
			}
			if (i >= 2) {
				if (isJ(s[i - 2]) && isJ(s[i - 1]) && isJ(s[i])) {
					return false;
				}
				if (!isJ(s[i - 2]) && !isJ(s[i - 1]) && !isJ(s[i])) {
					return false;
				}
			}
		}
		return l;
	}

	static boolean isJ(char c) {
		return !(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == '+');
	}
}