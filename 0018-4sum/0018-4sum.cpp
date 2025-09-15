class Solution {
public:
//better approach
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //set for unique val only
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //a hashset to store the elements from j->k
                set<long long>hashset;
                for(int k=j+1;k<n;k++){
                    //removing the 4th loop
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth=target-sum;
                        if(hashset.find(fourth)!=hashset.end()){
                            vector<int>temp={nums[i],nums[j],nums[k],(int)fourth};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                        hashset.insert(nums[k]);
                    }
                }
            }
        vector<vector<int>>res(st.begin(),st.end());
        return res;
    }
};