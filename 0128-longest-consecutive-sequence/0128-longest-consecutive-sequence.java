class Solution {
    public int longestConsecutive(int[] nums) {
        int longest=1;
        if(nums.length==0)return 0;
        Set<Integer>st=new HashSet<>();
        for(int i=0;i<nums.length;i++){
            st.add(nums[i]);
        }
        for(int x:st){
            if(!st.contains(x-1)){
                int cnt=1;
                int curr=x;
            while(st.contains(curr+1)){
                    cnt++;
                    curr=curr+1;
                }
            longest=Math.max(longest,cnt);
            }
        }
        return longest;

    }
}