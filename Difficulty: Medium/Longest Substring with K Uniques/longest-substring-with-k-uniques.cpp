class Solution {
  public:
  //sliding window
    int longestKSubstr(string &s, int k) {
        // code here
        int l=0,r=0,maxlen=-1;
        unordered_map<char,int>mpp;
        int n=s.size();
        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0)
                    mpp.erase(s[l]);
                l++;
            }
            if(mpp.size()==k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
        
    }
};