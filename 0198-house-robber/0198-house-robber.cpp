class Solution {
public:
    int dpfind(int n,vector<int>&nums,vector<int>&dp){
        if(n==0)return nums[0];
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
            int pick=nums[n]+dpfind(n-2,nums,dp);
            int notpick=dpfind(n-1,nums,dp);
        return dp[n]=max(pick,notpick);
    }
    int dp(int n,vector<int>&nums,int prev1,int prev2){
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(n>1)pick+=prev2;
            int notpick=prev1;
            int curr=max(pick,notpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
        
        
    }
    int rob(vector<int>& nums) {
        int prev1=nums[0];
        int prev2=0;
        int n=nums.size();
        return dp(n,nums,prev1,prev2);
        
    }
};