class Solution {
public:
//2ptr and sliding window
    int numberOfSubstrings(string s) {
        int cnt=0;
        vector<int>lastseen(3,-1);
        for(int i=0;i<s.size();i++){
             lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1 ){
                int minval=min({lastseen[0],lastseen[1],lastseen[2]});
                cnt=cnt+(minval+1);
            }
        }
        return cnt;
    }
};