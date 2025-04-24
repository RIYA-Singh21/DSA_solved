class Solution {
    int upperbound(int[]nums,int target){
        int low=0; int high=nums.length-1;
        int ans=nums.length;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
            
        }
        return ans;
    }
    int lowerbound(int[]nums,int target){
        int low=0; int high=nums.length-1;
        int ans=nums.length;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }else low=mid+1; 
        }
        return ans;

    }
    public int[] searchRange(int[] nums, int target) {
        //check for edge cases where ele is not there 
        if(lowerbound(nums,target)==nums.length || nums[lowerbound(nums,target)]!=target) 
            return new int[]{-1,-1};
        return new int[] {lowerbound(nums,target),upperbound(nums,target)-1};
    }
}