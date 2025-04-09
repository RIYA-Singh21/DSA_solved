class Solution {
    //monotonic stack O(2n)
    public int[] nextGreaterElements(int[] nums) {
        Stack<Integer>st=new Stack<>();
        int n=nums.length;
        int[]nge=new int [n];
        for(int i=2*n-1;i>=0;i--){
            //index= i%n
            while(!st.isEmpty() && st.peek()<=nums[i%n])
                st.pop();
            //update nge only when the index is <= n
            if(i<n){
                nge[i]=!st.isEmpty()?st.peek():-1;
            } 
            st.push(nums[i%n]);
        }
        return nge;
    }
}