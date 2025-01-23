//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int f(int ind,int capacity,vector<int>val,vector<int>wt,vector<vector<int>>&dp){
        if(ind==0){
            if(wt[0]<=capacity)return val[0];
            return 0;
        }
        if(dp[ind][capacity]!=-1)return dp[ind][capacity];
        int notpick=0+f(ind-1,capacity,val,wt,dp);
        int pick=INT_MIN;
        if(wt[ind]<=capacity)pick=val[ind]+f(ind-1,capacity-wt[ind],val,wt,dp);
        return dp[ind][capacity]=max(pick,notpick);
    }
    
    //tabulation
    int tab(int ind,int capacity,vector<int>val,vector<int>wt,vector<vector<int>>&dp){
        //base case 
        
        for(int i=wt[0];i<=capacity;i++){
            if (i >= wt[0])dp[0][i]=val[0];
        }
        
        for(int i=1;i<ind;i++){
            for(int weight=0;weight<=capacity;weight++){
               int notpick=0+dp[i-1][weight];
                int pick=INT_MIN;
             if(wt[i]<=weight) pick=val[i]+dp[i-1][weight-wt[i]];  
             
             dp[i][weight]=max(pick,notpick);
            }
        
        }
        
        return dp[ind-1][capacity];
    }
    
    
    
    
    
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        //vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        //return f(n-1,capacity,val,wt,dp);
        return tab(n,capacity,val,wt,dp);
    }

    
    
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends