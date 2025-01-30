class Solution {
public:
    bool ispalindrome(string str,int start,int end){
        while(start<=end){
            if(str[start++]!=str[end--])
                return false;
        }
        return true;
    }
    void f(int ind,string s,vector<vector<string>>&ans,vector<string>subst){
        if(ind==s.size()){
            ans.push_back(subst);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s,ind,i)){
                subst.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,ans,subst);
                subst.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>subst;
        f(0,s,ans,subst);
        return ans;
    }
};