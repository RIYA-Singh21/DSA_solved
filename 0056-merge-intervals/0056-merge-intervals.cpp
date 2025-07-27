class Solution {
public:
//solve in a single pass
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            //check if ans is empty or the number is greater 
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                //add the element to ans
                ans.push_back(intervals[i]);
            }else{
                if(intervals[i][0]<=ans.back()[1]){
                    //if it's overlapping
                    ans.back()[1]=max(intervals[i][1],ans.back()[1]);
                }
            }
        }
        return ans;
    }
};