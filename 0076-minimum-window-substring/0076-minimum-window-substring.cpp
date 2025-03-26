class Solution {
public:
//better approach: using 2 ptrs TC O(N^2) and SC O(256)
    string minWindow(string s, string t) {
        int minlen=INT_MAX;
        int starting_ind=-1;
        int cnt=0,r=0,l=0; //left n right ptrs
        int n=s.size(); int m=t.size();
            //initialize the hash map
            int hash[256]={0};
        for(int i=0;i<m;i++)
            hash[t[i]]++;
        while(r<n){
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;
            //as long as count == t.size() shrink the substr as much as possible
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    starting_ind=l;
                }
                //remove the element at l from substr so increase it's value int he map
                hash[s[l]]++;
                if(hash[s[l]]>0)cnt=cnt-1;
                l++;
            }
            r=r+1;
        }
           
    
        return starting_ind==-1?"": s.substr(starting_ind,minlen);
    }
};