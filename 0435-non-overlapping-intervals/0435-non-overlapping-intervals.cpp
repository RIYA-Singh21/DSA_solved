class Solution {
static bool comp(vector<int>val1,vector<int>val2){
    return val1[1]<val2[1];
}
public:
//opposite of n meetings in a room
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=1;
        int lastexit=intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=lastexit){
                cnt++;
                lastexit=intervals[i][1];
            }
        }
        return n-cnt;
    }
};