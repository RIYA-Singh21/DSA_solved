class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int c=0; int max=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                c++;
                if(c>max)max=c;
            }else c=0;
        }
        return max;
    }
}