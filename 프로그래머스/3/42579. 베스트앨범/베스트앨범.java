import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        Map<String, Integer> genreCnt = new HashMap<>();
        for (int i = 0; i < genres.length; i++) {
            genreCnt.put(genres[i], genreCnt.getOrDefault(genres[i], 0) + plays[i]);
        }
        Queue<Data> pq = new PriorityQueue<>();
        for(var entry:genreCnt.entrySet()) {
            pq.add(new Data(entry.getValue(), entry.getKey()));
        }
        List<Integer> answer=new ArrayList<>();
        while(!pq.isEmpty()){
            Data data = pq.poll();
            List<List<Integer>> list = new ArrayList<>();
            for(int i=0;i<genres.length;i++){
                if(genres[i].equals(data.genre)){
                    list.add(List.of(-plays[i],i));
                }
            }
            list.sort(Comparator.comparing(o -> o.get(0)));
            int cnt=0;
            
            for(int i=0;i<list.size();i++){
                answer.add(list.get(i).get(1));
                cnt++;
                if(cnt==2){
                    break;
                }
            }
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
    
    class Data implements Comparable<Data> {
        public int cnt;
        public String genre;
        
        public Data(int cnt, String genre) {
            this.cnt = cnt;
            this.genre = genre;
        }
        
        public int compareTo(Data d) {
            return d.cnt - this.cnt;
        }
    }
}