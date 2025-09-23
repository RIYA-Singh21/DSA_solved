class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0;
        int maxsum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++)
            lsum+=cardPoints[i];
            //initially maxsum=lsum
            maxsum=lsum;
        
        //now decrement from left and add right side elements for maxsum
        int rightend=n-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rightend];
            rightend--;
            maxsum=max(maxsum,lsum+rsum);
        }
    return maxsum;
    }
};