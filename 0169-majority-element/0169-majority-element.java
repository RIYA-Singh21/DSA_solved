class Solution {
    public int majorityElement(int[] nums) {
        int cnt=0;
        int el=-1;
        for(int i=0;i<nums.length;i++){
            if(cnt==0){
                cnt++;
                el=nums[i];
            }
            else if(nums[i]==el){
                cnt++;
            }else{
                cnt--;
            }
        }
        if(cnt>0)return el;
        else return -1;
    }
}