import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static int n;
	static String s;
	static int[] cnt;
	static StringBuilder ans = new StringBuilder();

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			s = br.readLine();
			cnt = new int[26];
			for (int j = 0; j < s.length(); j++) {
				cnt[s.charAt(j) - 'a']++;
			}
			go(new StringBuilder());
		}
		System.out.println(ans);
	}

	static void go(StringBuilder sb) {
		if (sb.length() == s.length()) {
			ans.append(sb).append("\n");
			return;
		}

		for (int i = 0; i < 26; i++) {
			if (cnt[i] > 0) {
				cnt[i]--;
				sb.append((char) (i + 'a'));
				go(sb);
				cnt[i]++;
				sb.deleteCharAt(sb.length() - 1);
			}
		}
	}
}