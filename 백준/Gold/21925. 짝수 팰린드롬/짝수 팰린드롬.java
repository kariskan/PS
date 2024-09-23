import java.io.*;
import java.util.*;

class Main {
	public void solve() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		List<Integer> arr = new ArrayList<>();

		st = new StringTokenizer(br.readLine());
		int answer = 0;
		boolean[] check = new boolean[N];
		int head = 0;
		int tail = 0;
		for(int i = 0; i < N; i++) {
			tail = i;
			arr.add(Integer.parseInt(st.nextToken()));
			if (isPalindrome(arr)) {
				Arrays.fill(check, head, tail + 1, true);
				head = tail + 1;
				answer++;
				arr.clear();
			}
		}
		if (answer == 0) System.out.println("-1");
		else {
			boolean checker = true;
			for (int i = 0; i < N; i++) {
				// System.out.println(check[i]);
				checker &= check[i];
			}
			if (checker)
				System.out.println(answer);
			else
				System.out.println("-1");
		}
	}

	private boolean isPalindrome(List<Integer> arr) {
		int N = arr.size();
		if (N != 0 && N % 2 == 0) {
			for(int i = 0; i < (N / 2); i++) {
				if (!Objects.equals(arr.get(i), arr.get(N - i - 1))) return false;
			}
			return true;
		} else {
			return false;
		}
	}

	public static void main(String[] args) throws Exception {
		new Main().solve();
	}
}