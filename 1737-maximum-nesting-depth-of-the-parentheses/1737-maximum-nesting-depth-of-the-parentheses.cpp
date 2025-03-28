class Solution {
public:
    int maxDepth(string s) {
     int cnt=0,res=0;
     for(char c:s){
        if(c=='(') cnt++;
        else if(c==')')cnt--;
        res=max(res,cnt);
     }   
     return res;
    }
};