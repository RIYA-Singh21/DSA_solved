class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(255,-1);
        int l=0,r=0,maxlen=0;
        while(r<s.size()){
            if(mpp[s[r]]!=-1){
                if(mpp[s[r]]>=l){
                    //update left
                     l=mpp[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxlen=max(len,maxlen);
            mpp[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};