import java.util.*;

class Solution {
    
    int[][] map = new int[51][51];
    
    public int solution(String begin, String target, String[] words) {
        List<String> list = new ArrayList(Arrays.asList(words));
        list.add(begin);
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (can(list.get(i), list.get(j))) {
                    map[i][j] = 1;
                }
            }
        }
        for (int k = 0; k < list.size(); k++) {
            for (int i = 0; i < list.size(); i++) {
                for (int j = 0; j < list.size(); j++) {
                    if (map[i][k]>0&&map[k][j]>0&&(map[i][j]==0||map[i][j]>map[i][k]+map[k][j])){
                        map[i][j]=map[i][k]+map[k][j];
                    }
                }
            }
        }
        for(int i=0;i<list.size();i++){
            if(list.get(i).equals(target)){
                return map[list.size()-1][i];
            }
        }
        return 0;
    }
    
    boolean can(String s1, String s2) {
        int cnt = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                cnt++;
            }
        }
        return cnt == 1;
    }
}