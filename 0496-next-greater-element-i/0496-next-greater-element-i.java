class Solution {
    public int ngreater(int num, int[]arr){
        for(int i=0;i<arr.length;i++){
            if(arr[i]==num){
                for(int j=i+1;j<arr.length;j++){
                    if(arr[j]>num){
                        return arr[j];
                    }
                }
                //if there's no greater element than num 
                return -1;
            }
        }
        return -1;
    }
    //brute force 
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n=nums1.length;
        int[]res=new int[n];
        for(int i=0;i<n;i++){
            res[i]=ngreater(nums1[i],nums2);
        }
        return res;

    }
}