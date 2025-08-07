class Solution {
public:
//sliding window
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0;
        int len=INT_MAX;
        int total=0;
        while(r<nums.size()){
            total+=nums[r];
            while(total>=target){
                len=min(len,r-l+1);
                total-=nums[l];
                l++;
            }
            r++;
        }
        return len!=INT_MAX?len:0;
        
    }
};