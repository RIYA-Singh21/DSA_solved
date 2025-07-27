class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int cnt=1;
        vector<int> prev=points[0];
        for(int i=1;i<points.size();i++){
            //current starting and ending
            int currSP=points[i][0];
            int currEP=points[i][1];
            int prevSP=prev[0];
            int prevEP=prev[1];
            //no overlap condn
            if(points[i][0]>prevEP){
                cnt++;
                prev=points[i];
            }else{
                //overlapping , change intervals
                //starting point will be max of both the intervals
                prev[0]=max(currSP,prevSP);
                //ending point will be min of both the intervals
                prev[1]=min(currEP,prevEP);
            }
        }
        return cnt;
    }
};