class Solution {
public:
    double myPow(double x, int n) {
        long long pow=n;
        double ans=1.0;
        if(n<0) pow= -1*pow;
        while(pow>0){
            if(pow%2==1){
                ans=ans*x;
                pow=pow-1;
            }
            else{
                x=x*x;
                pow=pow/2;
            }
        }
        if(n<0) ans=double (1.0)/double(ans);
        return ans;  
    }
};