import java.util.*;

class Solution {
    
    int n,m;
    int[][] vis = new int[50][50];
    int[] dx={0,0,1,-1};
    int[] dy={1,-1,0,0};
    
    public int solution(int[][] board, int[][] table) {
        n = board.length;
        m = board[0].length;
        List<int[][]> bp = dfs(board,0);
        List<int[][]> tp = dfs(table,1);
        
        int answer=0;
        int[] tpVis = new int[tp.size()];
        for(int i=0;i<bp.size();i++){
            for(int j=0;j<tp.size();j++){
                if(tpVis[j]>0){
                    continue;
                }
                if (check(bp.get(i),tp.get(j))){
                    for(int i1=0;i1<tp.get(j).length;i1++){
                        for(int j1=0;j1<tp.get(j)[0].length;j1++){
                            if(tp.get(j)[i1][j1]==1){
                                answer++;
                            }
                        }
                    }
                    tpVis[j]=1;
                    break;
                }
            }
        }
        return answer;
    }
    
    int[][] rotate(int[][] r) {
        int[][] res = new int[r[0].length][r.length];
        for (int i = 0; i < res.length; i++) {
            for (int j = 0; j < res[i].length; j++) {
                res[i][j] = r[j][res.length - i - 1];
            }
        }
        return res;
    }
    
    List<int[][]> dfs(int[][] board, int flag) {
        vis = new int[50][50];
        List<int[][]> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (board[i][j]==flag&&vis[i][j]==0) {
                    Queue<Pair> temp = new ArrayDeque<>();
                    Queue<Pair> q = new ArrayDeque<>();
                    
                    q.add(new Pair(i,j));
                    vis[i][j] = 1;
                    
                    int minx=n;
                    int miny=m;
                    int maxx=0;
                    int maxy=0;
                    
                    while (!q.isEmpty()) {
                        Pair d = q.poll();
                        int x = d.first;
                        int y = d.second;
                        
                        temp.add(new Pair(x,y));
                        minx=Math.min(minx,x);
                        miny=Math.min(miny,y);
                        maxx=Math.max(maxx,x);
                        maxy=Math.max(maxy,y);
                        
                        for(int k=0;k<4;k++){
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx>=0&&nx<n&&ny>=0&&ny<m&&vis[nx][ny]==0&&board[nx][ny]==flag){
                                vis[nx][ny]=1;
                                q.add(new Pair(nx,ny));
                            }
                        }
                    }
                    
                    int[][] insert = new int[maxx-minx+1][maxy-miny+1];
                    while (!temp.isEmpty()){
                        Pair p = temp.poll();
                        insert[p.first-minx][p.second-miny]=1;
                    }
                    v.add(insert);
                }
            }
        }
        return v;
    }
    
    boolean check(int[][] v1, int[][] v2) {
        for (int r=0;r<4;r++){
            v2 = rotate(v2);
            if (v1.length != v2.length || v1[0].length != v2[0].length) {
                continue;
            }
            boolean flag = true;
            for (int i = 0; i < v1.length; i++) {
                for(int j = 0; j < v1[0].length; j++) {
                    if (v1[i][j] != v2[i][j]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
    
    class Pair {
        public int first;
        public int second;
        
        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}