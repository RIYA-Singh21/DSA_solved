class Solution {
    public int dpPath(int i,int j,int m, int n,int[][]dp){
        if(i==m-1 && j==n-1)return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j]= dpPath(i+1,j,m,n,dp)+dpPath(i,j+1,m,n,dp);
    }
    public int uniquePaths(int m, int n) {
        int[][]dp=new int[m][n];
        for(int[] row:dp){
            Arrays.fill(row,-1);
        }
        return dpPath(0,0,m,n,dp);
    }
}