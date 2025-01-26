#define MOD 1000000007
class Solution {
public:
 int myPow( long long x, long long n) {
        long long pow=n;
        long long ans=1;
        while(pow>0){
            if(pow%2==1){
                ans=(ans*x) % MOD;
                pow=pow-1;
            }
            else{
                x=(x*x) %MOD;
                pow=pow/2;
            }
        }
        return ans;
 }
    int countGoodNumbers(long long n) {
        long long even= n/2+n%2;
        long long odd=n/2;
        long long evenind=myPow(5,even);
        long long oddind=myPow(4,odd);
        return (evenind *oddind)%MOD;
    }
};