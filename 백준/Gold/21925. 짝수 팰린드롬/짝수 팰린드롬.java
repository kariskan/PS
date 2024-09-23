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
		int head = 0;
		for(int i = 0; i < N; i++) {
			arr.add(Integer.parseInt(st.nextToken()));
			if (isPalindrome(arr)) {
				head = i + 1;
				answer++;
				arr.clear();
			}
		}
		if (answer == 0) System.out.println("-1");
		else {
			if (head == N)
				System.out.println(answer);
			else
				System.out.println("-1");
		}
	}

	private boolean isPalindrome(List<Integer> arr) {
		int N = arr.size();
		if (N != 0 && N % 2 == 0) {
			for(int i = 0; i < N / 2; i++) {
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