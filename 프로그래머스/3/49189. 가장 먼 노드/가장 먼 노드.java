import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
		int answer = 0;
		List<List<Integer>> list = new ArrayList<>();
		for(int i=0;i<n+1;i++){
			list.add(new ArrayList<>());
		}
		for(int i=0;i<edge.length;i++){
			list.get(edge[i][0]).add(edge[i][1]);
			list.get(edge[i][1]).add(edge[i][0]);
		}
		List<Integer> dis=new ArrayList<>();
        for(int i=0;i<n+1;i++){
            dis.add(Integer.MAX_VALUE);
        }
		Queue<Pair> pq=new PriorityQueue<>();
		dis.set(1,0);
		pq.add(new Pair(0,1));
		int ma=0;
		while(!pq.isEmpty()){
			Pair pair = pq.poll();
			ma=Math.max(ma,dis.get(pair.second));
			if(dis.get(pair.second)<-pair.first){
				continue;
			}
			for(int i=0;i<list.get(pair.second).size();i++){
				int nxNode=list.get(pair.second).get(i);
				int nxCost=-pair.first+1;
				if(dis.get(nxNode)>nxCost){
					dis.set(nxNode,nxCost);
					pq.add(new Pair(-nxCost,nxNode));
				}
			}
		}
		for(int i=2;i<=n;i++){

			if(ma==dis.get(i)){
				answer++;
			}
		}

		return answer;
	}

	class Pair implements Comparable<Pair> {
		public int first;
		public int second;

		public Pair(int first, int second){
			this.first=first;
			this.second=second;
		}

		public int compareTo(Pair p){
			if(this.first==p.first){
				return p.second-this.second;
			}
			return p.first-this.first;
		}
	}
}