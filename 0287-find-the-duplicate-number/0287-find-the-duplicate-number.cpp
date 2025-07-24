class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        //move slow-once, fast-twice
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast)break;
        }
        //when fast==slow, move fast- once , slow-once until they collide
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
        
    }
};