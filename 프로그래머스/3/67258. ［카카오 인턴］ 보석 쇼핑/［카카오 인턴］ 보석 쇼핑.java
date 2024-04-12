import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = {1,gems.length};
        Map<String,Integer> map = new HashMap<>();
        for(int i=0;i<gems.length;i++){
            map.put(gems[i],map.getOrDefault(gems[i],0)+1);
        }
        int cnt=map.size(),left=0,right=0;
        map.clear();
        map.put(gems[0],1);
        
        while(right<gems.length){
            if(map.size()>=cnt){
                map.put(gems[left],map.get(gems[left])-1);
                if(map.get(gems[left])==0){
                    map.remove(gems[left]);
                }
                if(answer[1]-answer[0]>right-left){
                    answer=new int[]{left+1,right+1};
                }
                left++;
            }else{
                right++;
                if(right==gems.length){
                    break;
                }
                map.put(gems[right],map.getOrDefault(gems[right],0)+1);
            }
        }
        
        return answer;
    }
}