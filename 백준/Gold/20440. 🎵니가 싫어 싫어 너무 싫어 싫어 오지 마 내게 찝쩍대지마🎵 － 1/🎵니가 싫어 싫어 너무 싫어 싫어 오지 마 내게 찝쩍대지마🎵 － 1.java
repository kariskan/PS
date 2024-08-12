import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		List<int[]> v = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			v.add(new int[] {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});
		}

		int num = 0;
		Map<Integer, Integer> compressionMap = new HashMap<>();
		List<Integer> temp = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			temp.add(v.get(i)[0]);
			temp.add(v.get(i)[1]);
		}
		temp.sort(Comparator.naturalOrder());
		for (int i = 0; i < temp.size(); i++) {
			int key = temp.get(i);
			if (compressionMap.containsKey(key)) {
				continue;
			}
			compressionMap.put(key, num++);
		}

		int[] arr = new int[num + 1];
		for (int i = 0; i < n; i++) {
			int l = v.get(i)[0];
			int r = v.get(i)[1];

			arr[compressionMap.get(l)]++;
			arr[compressionMap.get(r)]--;
		}

		for (int i = 1; i < num; i++) {
			arr[i] += arr[i - 1];
		}
		int prev = -1;
		List<int[]> list = new ArrayList<>();
		for (int i = 0; i < num; i++) {
			if (prev != arr[i]) {
				int idx = i;
				while (idx < num && arr[i] == arr[idx]) {
					idx++;
				}
				list.add(new int[] {arr[i], i, idx});
				i = idx - 1;
			}
		}
		Map<Integer, Integer> revCompressionMap = new HashMap<>();
		for (var e : compressionMap.entrySet()) {
			revCompressionMap.put(e.getValue(), e.getKey());
		}
		list.sort((a, b) -> {
			if (a[0] == b[0]) {
				if (a[2] - a[1] == b[2] - b[1]) {
					return a[1] - b[1];
				}
				return -(a[2] - a[1]) + (b[2] - b[1]);
			}
			return b[0] - a[0];
		});

		System.out.println(list.get(0)[0]);
		System.out.println(revCompressionMap.get(list.get(0)[1]) + " " + revCompressionMap.get(list.get(0)[2]));
	}
}
