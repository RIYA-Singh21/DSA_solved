class Solution {
    //optimal: sum of natural no.
    public int missingNumber(int[] nums) {
        int n=nums.length;
        int s=(n*(n+1))/2;
        int s1=0;
        for(int i=0;i<n;i++){
            s1+=nums[i];
        }
        return s-s1;
    }
}