class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        //hashing
        List<List<Integer>> list=new ArrayList<>();
        Set<List<Integer>>st=new HashSet<>();
        for(int i=0;i<nums.length;i++){
            Set<Integer> st1=new HashSet<>();
            for(int j=i+1;j<nums.length;j++){
                int third=-(nums[i]+nums[j]);
                if(st1.contains(third)){
                    List<Integer>l=Arrays.asList(nums[i],nums[j],third);
                    Collections.sort(l);
                    st.add(l);
                }
                st1.add(nums[j]);
            }  
        }
        list.addAll(st);
        return list;
    }
}