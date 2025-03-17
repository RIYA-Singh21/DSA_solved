class Solution {
public:
//optimal soln : O(n) (prefix sum approach)
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        //initialize 0,1
        mpp[0]=1;
        int prefixsum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int remove=prefixsum-k;
            cnt+=mpp[remove];
            mpp[prefixsum]+=1;
        }
        return cnt;
    }
};