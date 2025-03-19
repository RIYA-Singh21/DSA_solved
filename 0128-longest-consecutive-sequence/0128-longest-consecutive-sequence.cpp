class Solution {
public:
//optimized using set ds
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int>st;
        //insert elements in the set
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        //iterate through the set
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt++;
                }
            longest=max(longest,cnt);
            }
        }
        return longest;
    }
};