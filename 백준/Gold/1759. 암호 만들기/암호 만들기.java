import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static List<Character> v = new ArrayList<>();
	static int n, m;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++) {
			v.add(st.nextToken().charAt(0));
		}

		v.sort(Comparator.naturalOrder());

		go(0, new StringBuilder());
	}

	static void go(int idx, StringBuilder sb) {
		if (sb.length() == n) {
			if (check(sb)) {
				System.out.println(sb);
			}
			return;
		}
		if (idx >= m) {
			return;
		}
		sb.append(v.get(idx));
		go(idx + 1, sb);
		sb.delete(sb.length() - 1, sb.length());
		go(idx + 1, sb);
	}

	private static boolean check(StringBuilder sb) {
		int first = 0, second = 0;
		for (int i = 0; i < sb.length(); i++) {
			if (sb.charAt(i) == 'a' || sb.charAt(i) == 'i' || sb.charAt(i) == 'o'
				|| sb.charAt(i) == 'u' || sb.charAt(i) == 'e') {
				first++;
			} else {
				second++;
			}
		}
		return first >= 1 && second >= 2;
	}
}
