class Solution {
public:
 void f(int ind,int target,vector<int>arr,vector<vector<int>>&ans,vector<int>&combo){
        if(target==0) {
            ans.push_back(combo);
            return;
        }
        
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            combo.push_back(arr[i]);
            f(i+1,target-arr[i],arr,ans,combo);
            combo.pop_back(); // pop the extra element while coming back from the recursive call
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>combo;
        f(0,target,candidates,ans,combo);
        return ans;
    }
};