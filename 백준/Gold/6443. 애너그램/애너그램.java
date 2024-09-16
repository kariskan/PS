import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class Main {

	static int n;
	static String s;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			s = br.readLine();
			char[] a = s.toCharArray();
			Arrays.sort(a);
			s = new String(a);
			go(new StringBuilder(), new HashSet<>(), new boolean[s.length()]);
		}
	}

	static void go(StringBuilder sb, Set<String> set, boolean[] vis) {
		if (sb.length() == s.length()) {
			System.out.println(sb);
			return;
		}

		for (int i = 0; i < s.length(); i++) {
			if (!vis[i]) {
				sb.append(s.charAt(i));
				if (set.contains(sb.toString())) {
					sb.deleteCharAt(sb.length() - 1);
					continue;
				}
				vis[i] = true;
				set.add(sb.toString());
				go(sb, set, vis);
				vis[i] = false;
				sb.deleteCharAt(sb.length() - 1);
			}
		}
	}
}