class Solution {
public:
    int ladderLength(string beginword, string endword, vector<string>& wordlist) {
     queue<pair<string,int>>q;
     q.push({beginword,1});
     unordered_set<string> st(wordlist.begin(),wordlist.end());
     st.erase(beginword);
     while(!q.empty()){
        string word=q.front().first;
        int num=q.front().second;
        q.pop();
        if(word==endword)return num;
        for(int i=0;i<word.size();i++){
            string original=word;
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    q.push({word,num+1});
                    st.erase(word);
                }
            }
            word=original;
        }
     }
     return 0;
    }
};