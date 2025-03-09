class Solution {
public:
    string longestPalindrome(string s) {
        int r,l;
        int maxstr=0;
        string res="";
        for (int i=0;i<s.length();i++){
            //for odd palindromes
            r=l=i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>maxstr){
                    maxstr=r-l+1;
                    res=s.substr(l,r-l+1);
                }
                l--; r++;
            }
            //for even palindromes
            l=i,r=i+1;
              while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>maxstr){
                    maxstr=r-l+1;
                    res=s.substr(l,r-l+1);
                }
                l--; r++;
            }
        }
        return res;
    }
};