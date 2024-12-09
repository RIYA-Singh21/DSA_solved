class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>tsubset;
        int n =nums.size();
        int x=pow(2,n);
        for(int i=0;i<x;i++){
            vector<int>list;
            //condn to check if the bit is set
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    list.push_back(nums[j]);
            }
            }
            tsubset.push_back(list);
        }
        return tsubset;
    
    }
};