class Solution {
public:
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
    int robber(vector<int>& nums) {
        int prev1=nums[0];
        int prev2=0;
        int n=nums.size();
        return dp(n,nums,prev1,prev2);
        
    }
    long int rob(vector<int>& nums) {
        vector<int>temp1,temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(robber(temp1),robber(temp2));
    }
};