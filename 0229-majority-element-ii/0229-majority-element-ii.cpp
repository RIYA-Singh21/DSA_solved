class Solution {
public:
//brute force , at max there can only be 2 elements in the ans 
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(ans.empty() || ans[0]!=nums[i]){
                int cnt=0;
                for(int j=0;j<nums.size();j++){
                    if(nums[j]==nums[i]) cnt++;
                }
                if(cnt>nums.size()/3) ans.push_back(nums[i]);
            }
            if(ans.size()==2)break;
        }
        return ans;
    }
};