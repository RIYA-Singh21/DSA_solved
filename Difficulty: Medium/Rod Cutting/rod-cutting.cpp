//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  //memoization
  int f(int ind,int N,vector<int>price,vector<vector<int>>&dp){
      if(ind==0){
          //(rodlength<=N)
          return (N)*price[0];
      }
      if(dp[ind][N]!=-1)return dp[ind][N];
      int nottake=0+f(ind-1,N,price,dp);
      int take=INT_MIN;
        int rodlength=ind+1;
      if(rodlength<=N) take =price[ind]+f(ind,N-rodlength,price,dp); 
      
      return dp[ind][N]=max(take,nottake);
  }
    int cutRod(vector<int> &price) {
        // code here
        int N=price.size();
        //vector<vector<int>>dp(N,vector<int>(N+1,-1));
        //return f(N-1,N,price,dp);
        //tabulation
        vector<vector<int>>dp(N,vector<int>(N+1,0));
        for(int n=0;n<=N;n++)
        dp[0][n]=n*price[0];
        
        for(int ind=1;ind<N;ind++){
            for(int n=0;n<=N;n++){
                
                int nottake=0+dp[ind-1][n];
                int take=INT_MIN;
                int rodlength=ind+1;
                if(rodlength<=n) take =price[ind]+dp[ind][n-rodlength]; 
      
                dp[ind][n]=max(take,nottake);
            }
        }
        return dp[N-1][N];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends