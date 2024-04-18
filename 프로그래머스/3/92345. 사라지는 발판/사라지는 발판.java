class Solution {
    
    int[] x = {0,0,1,-1};
    int[] y = {1,-1,0,0};
    int n;
    int m;
    
    public int solution(int[][] board, int[] aloc, int[] bloc) {
        n=board.length;
        m=board[0].length;
        return go(board,aloc,bloc,0).second;
    }
    
    boolean range(int[][] board, int nx, int ny) {
        return nx>=0&&nx<n&&ny>=0&&ny<m&&board[nx][ny]>0;
    }
    
    boolean isGameEnd(int[][] board, int[] loc) {
        for(int i=0;i<4;i++){
            int nx=loc[0]+x[i];
            int ny=loc[1]+y[i];
            if (range(board,nx,ny)){
                return false;
            }
        }
        return true;
    }
    
    Pair go(int[][] board, int[] a, int[] b, int cnt) {
        if(isGameEnd(board, a)) {
            return new Pair(0,0);
        }
        
        if (a[0]==b[0]&&a[1]==b[1]){
            return new Pair(1,1);
        }
        
        int min=Integer.MAX_VALUE;
        int max=Integer.MIN_VALUE;
        int win = 0;
        board[a[0]][a[1]]=0;
        for (int i=0;i<4;i++){
            int nx=a[0]+x[i];
            int ny=a[1]+y[i];
            if (!range(board,nx,ny)){
                continue;
            }
            Pair res = go(board,b, new int[]{nx,ny}, cnt + 1);
            if (res.first==1){
                max=Math.max(max,res.second);
            } else {
                min = Math.min(min,res.second);
                win=1;
            }
        }
        board[a[0]][a[1]]=1;
        
        return new Pair(win,win==1?min+1:max+1);
    }
    
    class Pair {
        public int first;
        public int second;
        
        public Pair(int first, int second) {
            this.first=first;
            this.second=second;
        }
    }
}