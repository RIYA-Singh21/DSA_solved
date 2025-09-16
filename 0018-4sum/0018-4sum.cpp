class Solution {
public:
//optimal approach- keep i,j const  move k and l as 2 ptrs
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            //move till you find a diff element than the last one
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                //if j is not the first ele 
                if(j!=i+1 && nums[j]==nums[j-1])continue;
                int k=j+1,l=n-1;
                while(k<l){
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(target==sum){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                        while(k<l && nums[k]==nums[k-1])k++;
                        while(k<l && nums[l]==nums[l+1])l--;
                    }
                    else if(target<sum) l--;
                    else k++;
                
                }
            }
        }
        return ans;
    }
};