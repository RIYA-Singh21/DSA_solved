class Solution {
    public int findDuplicate(int[] nums) {
       //use the hare n tortoise method
       //first make the cycle
       int slow=nums[0];
       int fast=nums[0];
       do{
        slow=nums[slow];
        //move 2 spaces
        fast=nums[nums[fast]];
       }while(slow!=fast);
       fast=nums[0];
       while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
       }
       return slow;
    }
}