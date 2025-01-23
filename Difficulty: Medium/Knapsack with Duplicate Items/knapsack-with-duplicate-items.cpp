//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  //memoization 
    int f(int ind,int maxweight,vector<int>val,vector<int>wt,vector<vector<int>>&dp){
        if(ind==0){
            if(wt[0]<=maxweight) return (int(maxweight/wt[0]))*val[0];
            return 0;
        }
        if(dp[ind][maxweight]!=-1) return dp[ind][maxweight];
         
        int notpick=0+ f(ind-1,maxweight,val,wt,dp);
        int pick=INT_MIN;
        if(wt[ind]<=maxweight) pick= val[ind]+f(ind,maxweight-wt[ind],val,wt,dp);
        
        return dp[ind][maxweight]=max(pick,notpick);
        
    }
    int knapSack(vector<int>& val, vector<int>& wt, int maxweight) {
        // code here
        int n=val.size();
        //memoization
        //vector<vector<int>>dp(n,vector<int>(maxweight+1,-1));
        //return f(n-1,maxweight,val,wt,dp);
        vector<vector<int>>dp(n,vector<int>(maxweight+1,0));
        for(int i=0;i<=maxweight;i++) dp[0][i]=(int(i/wt[0]))*val[0];
        
         for(int i=1;i<n;i++){
            for(int weight=0;weight<=maxweight;weight++){
               int notpick=0+dp[i-1][weight];
                int pick=INT_MIN;
             if(wt[i]<=weight) 
                pick=val[i]+dp[i][weight-wt[i]];  
             
             dp[i][weight]=max(pick,notpick);
            }
        
        }
        return dp[n-1][maxweight];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends