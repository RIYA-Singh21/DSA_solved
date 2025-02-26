class Solution {
public:
struct compare{
    bool operator()(const pair<int,char>&a,const pair<int,char>&b){
        return a.first>b.first;
    }
};
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
                mp[ch]++;
            
        }
        vector<pair<int,char>>v;
        for(auto &it: mp){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),compare());
        string result="";
        for(auto it:v){
            result.append(string(it.first,it.second));
        }
    return result;
    }
};