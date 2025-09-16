class Solution {
public:
//sliding window TC: o(n) SC: O(26)
    int characterReplacement(string s, int k) {
        //int hash[26]={0}; 
        unordered_map<char,int>mpp;
        int l=0,r=0,maxlen=0;
        int maxfreq=0;
        int n=s.size();
        while(r<n){
            mpp[s[r]]++;
            maxfreq=max(maxfreq,mpp[s[r]]);
            //if the segment length is >k then decrease the window by 1
            if((r-l+1)-maxfreq>k){
                mpp[s[l]]--;
                //reset the maxfreq
                maxfreq=0;
                l++;
            }//if valid segment length <=k
            else{
                maxlen=max(maxlen,r-l+1);
            } 
            r++;
        }
        return maxlen;
    }
};