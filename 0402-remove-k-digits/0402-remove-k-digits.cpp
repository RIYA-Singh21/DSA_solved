class Solution {
public:
//using monotonic stack
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        for(int i=0;i<n;i++){
            //check if the stack already has some elements is > than num[i] then remove them
            while(!st.empty() && k>0 && st.top()-'0'>num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        //if after traversing k>0 then remove k elements from stack
        while(k>0){
            st.pop();
            k--;
        }
        //if the stack is empty them return 0
        if(st.empty())
            return "0";
        //initialize a result string
        string res="";
        //store the elements in res
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        //check if res has any 0's at the end , remove them 
        while(!res.empty() && res.back()=='0'){
            res.pop_back();
        }
        //now check if the result is empty or not , it might contain all 0's
        reverse(res.begin(),res.end());
        if(res.empty())
            return "0";
        else return res;

    }
};