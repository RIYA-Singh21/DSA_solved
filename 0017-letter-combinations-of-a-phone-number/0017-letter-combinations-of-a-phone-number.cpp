class Solution {
private:
    void countString(int index,string str, string digits, string map[] ,vector<string>&ans){
        if(index==digits.length()){
            ans.push_back(str);
            return;
        }
        int digit=digits[index]-'0';
        //character value
        string value=map[digit];
        for(int i=0;i<value.length();i++){
            str.push_back(value[i]);
            countString(index+1,str,digits,map,ans);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        //empty array
        if(digits=="")return {};
        //make an array to map
        string map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        countString(index,"",digits,map,ans);
        return ans;
    }
};