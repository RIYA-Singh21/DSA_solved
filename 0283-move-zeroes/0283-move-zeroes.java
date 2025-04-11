class Solution {
    public void moveZeroes(int[] nums) {
        //using 2ptr 
        int j=-1;
        int n=nums.length;
        //finding the 1st 0 in arr
        if(n>1){
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
                }
            }
        }
        if(j==-1)return;
        //start from j
        for(int i=j+1;i<n;i++){
            if(nums[i]!=0){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                j++;//increment j after each iteration
            }
        }
    }
}