class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int size=nums.size();
        for(int j=1;j<size;j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i++;
            }
        }
         //since i will follow 0 indexing
    return i+1;
    }
};