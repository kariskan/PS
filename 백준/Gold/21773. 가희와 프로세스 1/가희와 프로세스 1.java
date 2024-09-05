import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		var br = new BufferedReader(new InputStreamReader(System.in));
		var bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n, t;
		var st = new StringTokenizer(br.readLine());
		t = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());

		var pq = new PriorityQueue<Process>();

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int id, time, priority;
			id = Integer.parseInt(st.nextToken());
			time = Integer.parseInt(st.nextToken());
			priority = Integer.parseInt(st.nextToken());
			pq.offer(new Process(id, time, priority));
		}

		for (int i = 0; i < t; i++) {
			if (pq.isEmpty()) {
				break;
			}
			var now = pq.poll();
			bw.write(String.valueOf(now.id));
			bw.newLine();
			now.priority--;
			now.time--;
			if (now.time != 0) {
				pq.offer(now);
			}
		}

		bw.flush();
		bw.close();
	}

	static class Process implements Comparable<Process> {
		int id;
		int time;
		int priority;

		public Process(int id, int time, int priority) {
			this.id = id;
			this.time = time;
			this.priority = priority;
		}

		@Override
		public int compareTo(Process o) {
			if (this.priority == o.priority) {
				return this.id - o.id;
			}
			return o.priority - this.priority;
		}
	}
}