class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            int n=nums[i];
            int remain=target-n;
            if(mp.containsKey(remain))
                return new int[]{mp.get(remain),i};
            mp.put(n,i);
        }
        return new int[] {-1,-1};
    }
}