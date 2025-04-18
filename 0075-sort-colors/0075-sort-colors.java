class Solution {
    public void swap(int[]arr,int a,int b){
        int temp=arr[a];
        arr[a]=arr[b];
        arr[b]=temp;   
    }
    public void sortColors(int[] nums) {
        //dutch national flag algo
        int low=0;
        int mid=0;int high=nums.length-1;
        while(mid<=high){
            if(nums[mid]==0){
                //pass the indices 
                swap(nums,low,mid);
                low++; mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                //pass the indices 
                swap(nums,mid,high);
                high--;
            }
        }
    }
}