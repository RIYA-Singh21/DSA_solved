class Solution {
public:
bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<bool>prev(target+1,0),curr(target+1,0);
        prev[0]=curr[0]=true;
        if (arr[0] <= target)prev[arr[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int t=1;t<=target;t++){
                int nottake=prev[t];
                int take=false;
                if(t>=arr[ind])
                take=prev[t-arr[ind]];
                curr[t]= (take || nottake);
            }
            prev=curr;
        }
        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int tsum=0;
        for(int i=0;i<nums.size();i++)
        tsum+=nums[i];
        if(tsum%2)return false;
        int s=tsum/2;
        return isSubsetSum(nums,s);
    }
};