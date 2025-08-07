class Solution {
public:
//prefix sum -> s-k, (s=sum, k given value)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        //add (0,1) initially 
        mpp[0]=1;
        int cnt=0; int prefixSum=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            int remove=prefixSum-k;
            cnt+=mpp[remove];
            mpp[prefixSum]++;
        }
        return cnt;
    }
};