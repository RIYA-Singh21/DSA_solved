class Solution {
public:
    void f(int ind,int target,vector<int>arr,vector<vector<int>>&ans,vector<int>&combo){
        if(ind==arr.size()){
            if(target==0) ans.push_back(combo);
            return;
        }
        if(arr[ind]<=target){
            combo.push_back(arr[ind]);
            f(ind,target-arr[ind],arr,ans,combo);
            combo.pop_back(); // pop the extra element while coming back from the recursive call
        }
        f(ind+1,target,arr,ans,combo);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>combo;
        f(0,target,candidates,ans,combo);
        return ans;
    }
};