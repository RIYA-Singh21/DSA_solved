class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;

        for(int i=0;i<s.size();i++){
            unordered_map<char,int>mp;
            for(int j=i;j<s.size();j++){
                if(mp[s[j]]==1)break;
                int len=j-i+1;
                maxlen=max(maxlen,len);
                mp[s[j]]=1;
            }
        }
        return maxlen;
    }
};