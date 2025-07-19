class Solution {
private:
void solve(int start,int n,int k,vector<int>num,vector<vector<int>>&ans){
        if(num.size()==k){
            ans.push_back(num);
            return;
        }
        for(int i=start;i<=n;i++){
            num.push_back(i);
            solve(i+1,n,k,num,ans);
            num.pop_back();
        }
}
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>num;
        solve(1,n,k,num,ans);
        return ans;
    }
};