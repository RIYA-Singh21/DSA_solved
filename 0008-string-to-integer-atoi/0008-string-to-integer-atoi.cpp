class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int sign=1;
         int i=0;
        while(i<s.length() && s[i]==' '){
            i++;
        }
        if(s[i]=='-') {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')i++;
       
        while(i<s.length()){
            if(s[i]>='0' && s[i]<='9'){
                ans=ans*10+(s[i]-'0');// to convert char to int -> char-'0'=int
            
            if(ans>INT_MAX && sign==1) return INT_MAX;
            if(ans>INT_MAX && sign==-1) return INT_MIN;
            i++;
            }
        
        else return ans*sign;
        }
        return ans*sign;
    }
};