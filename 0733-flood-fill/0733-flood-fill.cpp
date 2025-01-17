class Solution {
    private:
    void dfs(int sr,int sc,vector<vector<int>>&ans,vector<vector<int>>&image,int inicolor,
        int delrow[],int delcol[],int color){
        ans[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<n &&  ncol>=0 && ncol<m && ans[nrow][ncol]!=color && 
            image[nrow][ncol]==inicolor)
            dfs(nrow,ncol,ans,image,inicolor,delrow,delcol,color);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int inicolor=image[sr][sc];
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,inicolor,delrow,delcol,color);
        return ans;
    }
};