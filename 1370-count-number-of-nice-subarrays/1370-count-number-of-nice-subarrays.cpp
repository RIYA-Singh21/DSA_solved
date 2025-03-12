class Solution {
public:
    int countSubArr(vector<int>&nums,int k){
        int r=0,l=0,cnt=0,sum=0;
    while(r<nums.size()){
        //take odd=1 and even =0
        sum+=(nums[r]%2);
        while(sum>k){
            sum-=(nums[l]%2);
            l++;
        }
        cnt+=(r-l+1);
        r++;
    }   
    return cnt;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
    return countSubArr(nums,k)-countSubArr(nums,k-1);
    }
};