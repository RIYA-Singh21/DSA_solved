class Solution {
    //monotonic stack 
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int n=nums2.length;
        int[]nge=new int[n];
        Stack<Integer>st=new Stack<>();
        for(int i=n-1;i>=0;i--){
            while(!st.isEmpty() && st.peek()<=nums2[i]){
                st.pop();
            }
            if(st.isEmpty()) nge[i]=-1;
            else nge[i]=st.peek();
            st.push(nums2[i]);
        }
        int m=nums1.length;
        int[]res=new int[m];
        //loop nums2 to find the nums1 element
        //from nums1
        for(int i=0;i<m;i++){
            //search in nums2
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    res[i]=nge[j];
                    break;
                }
            }
        }
        return res;
    }
}