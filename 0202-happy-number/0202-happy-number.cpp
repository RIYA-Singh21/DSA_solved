class Solution {
private:
int getsum(int n){
    int sum=0;
    while(n!=0){
        int digit=n%10;
        sum+=pow(digit,2);
        n/=10;
    }
    return sum;
}
public:
    bool isHappy(int n) {
        int slow=n;
        //start 1 step ahead of slow
        int fast=getsum(getsum(n));
        while(fast!=1 && slow!=fast){
            slow=getsum(slow);
            fast=getsum(getsum(fast));
        }
        return fast==1;
    }
};