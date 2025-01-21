class Solution {
public:
    bool static sortcomp(vector<int> val1,vector<int> val2){
        return val1[1]>val2[1];
    }
    int maximumUnits(vector<vector<int>>& boxtypes, int trucksize) {
        sort(boxtypes.begin(),boxtypes.end(),sortcomp);
        int maxsize=0;
        for(int i=0;i<boxtypes.size();i++){
            if(trucksize>=boxtypes[i][0]){
                maxsize+=(boxtypes[i][0]*boxtypes[i][1]);
                trucksize-=boxtypes[i][0];
            }
            else{
                maxsize+=(trucksize*boxtypes[i][1]);
                break;
            }
        }
        return maxsize;
    }
};