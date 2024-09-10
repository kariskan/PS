import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

	static int n;

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());
		Stack<Integer> st = new Stack<>();
		StringBuilder sb = new StringBuilder();
		int now = 1;
		for (int i = 0; i < n; i++) {
			int a = Integer.parseInt(br.readLine());
			if (now <= a) {
				while (now != a) {
					st.push(now);
					now++;
					sb.append("+\n");
				}
				st.push(now++);
				sb.append("+\n");
			}
			if (st.empty() || st.peek() != a) {
				System.out.println("NO");
				return;
			}
			st.pop();
			sb.append("-\n");
		}
		System.out.println(sb);
	}
}