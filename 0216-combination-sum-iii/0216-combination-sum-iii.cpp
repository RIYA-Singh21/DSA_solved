class Solution {
public:
   void findcomb(int start,int k, int n,vector<int>&comb,vector<vector<int>>&res){
        //base condn
        if( comb.size()==k){
            if(n==0)res.push_back(comb);
            return;
        }
        for(int i=start;i<=9;i++){
            comb.push_back(i);
            findcomb(i+1,k,n-i,comb,res);
            comb.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int>comb;
        findcomb(1,k,n,comb,res);
        return res;
    }
};