class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())return "";

        string pref=strs[0];
        int pref_len=strs[0].size();
        //iterate over the given vector
        for(int i=1;i<strs.size();i++){
            string s=strs[i];
            while(pref_len>s.length() || pref!=s.substr(0,pref_len)){
                pref_len--;
                if(pref_len==0)
                    return "";

                pref=pref.substr(0,pref_len);
            }
        }
        return pref;
    }
};