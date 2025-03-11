class Solution {
public:
//optimized : sliding window
    int characterReplacement(string s, int k) {
        int maxlen=0;
        int r=0,l=0;
        int maxfreq=0;
        int hash[26]={0};
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            if((r-l+1)-maxfreq>k){
                hash[s[l]-'A']--;
                l++;
                maxfreq=0;
            }
            if((r-l+1)-maxfreq<=k){
                maxlen=max(maxlen,r-l+1);
            }
        r++;
        }
        return maxlen;
    }
};