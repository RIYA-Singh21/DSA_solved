class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<int,char>>arr;
        for(auto &it:mp){
            arr.push_back({it.second,it.first});
        }
        sort(arr.begin(),arr.end(),greater<>());
        string res="";
        for(auto it:arr){
            res.append(string(it.first,it.second));
        }
        return res;
    }
};