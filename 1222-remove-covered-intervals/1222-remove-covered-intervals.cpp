class Solution {

struct comp{
    bool operator()(vector<int>&ele1,vector<int>&ele2){
        //1st element is in ascending order
        if(ele1[0]!=ele2[0])return ele1<ele2;
        //if both 1st ele are = then return the desc order of 2nd ele
        return ele1[1]>ele2[1];
    }
};
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp());

        int farthest=0; int cnt=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1]>farthest){
            //element isn't covered till  now increase the right limit
            farthest=intervals[i][1];
            cnt++;
            }
        }
        return cnt;
    }
};