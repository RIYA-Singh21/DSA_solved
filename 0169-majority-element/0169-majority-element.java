class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int num:nums){
            mp.put(num,mp.getOrDefault(num,0)+1);
        }
        for(int key:mp.keySet()){
            int val=mp.get(key);
            if(val>nums.length/2)
                return key;
        }
        return -1;
    }
}