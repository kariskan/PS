import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static String s;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		s = br.readLine();
		List<Character> v = new ArrayList<>();
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '-' || s.charAt(i) == '+') {
				v.add(s.charAt(i));
			}
		}
		String[] split = s.split("[-+]");
		int ans = Integer.parseInt(split[0]);
		boolean flag = false;
		for (int i = 0; i < v.size(); i++) {
			if (v.get(i) == '-') {
				flag = true;
				ans -= Integer.parseInt(split[i + 1]);
			} else {
				if (flag) {
					ans -= Integer.parseInt(split[i + 1]);
				} else {
					ans += Integer.parseInt(split[i + 1]);
				}
			}
		}
		System.out.println(ans);
	}
}