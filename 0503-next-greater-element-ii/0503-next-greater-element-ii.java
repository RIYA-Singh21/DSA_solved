class Solution {
    //better approach
    public int[] nextGreaterElements(int[] nums) {
        int n=nums.length;
        int[]nge=new int[n];
        Arrays.fill(nge,-1);
        for(int i=0;i<n;i++){
            //check till i+n-1
            for(int j=i+1;j<=i+n-1;j++){
                int ind=j%n;
                if(nums[i]<nums[ind]){
                    nge[i]=nums[ind];
                    break;
                }
            }
        }
        return nge;
    }
}