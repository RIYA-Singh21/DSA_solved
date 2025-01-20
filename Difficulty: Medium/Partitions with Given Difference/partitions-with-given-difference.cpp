//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int f(int ind,int sum,vector<int>arr,vector<vector<int>>&dp){
      if(ind==0){
            if(sum==0 && arr[0]==0) return 2;
            if(arr[0]==sum || sum==0) return 1;
            return 0;
        }
        if(dp[ind][sum]!=-1)return dp[ind][sum];
    
        int notpick=f(ind-1,sum,arr,dp);
        int pick=0;
        if(arr[ind]<=sum) pick=f(ind-1,sum-arr[ind],arr,dp);
        return dp[ind][sum]=pick+notpick;
  }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int totsum=0; int target_sum;
        int n=arr.size();
        for(int i=0;i<n;i++) totsum+=arr[i];
        if(totsum-d>=0 && (totsum-d)%2==0)
            target_sum=(totsum-d)/2;
        else return false;
            vector<vector<int>>dp(n,vector<int>(target_sum+1,-1));
            return f(n-1,target_sum,arr,dp);
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends