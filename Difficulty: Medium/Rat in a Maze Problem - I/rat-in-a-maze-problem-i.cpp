//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void f(int row,int col,vector<string>&ans,string move,vector<vector<int>> &mat,int n,
    vector<vector<int>>&vis){
        //make recursive func for each direction down,up,right,left lexographically
        //base case
        if(row==n-1 && col==n-1){
            ans.push_back(move);
            return;
        }
        //Down
        if(row+1<n && mat[row+1][col]==1 && !vis[row+1][col]){
            vis[row][col]=1;
            f(row+1,col,ans,move+'D',mat,n,vis);
            vis[row][col]=0;
        }
        //left
        if(col-1>=0 && mat[row][col-1]==1 && !vis[row][col-1]){
            vis[row][col]=1;
            f(row,col-1,ans,move+'L',mat,n,vis);
            vis[row][col]=0;
        }
        //right
        if(col+1<n && mat[row][col+1]==1 && !vis[row][col+1]){
            vis[row][col]=1;
            f(row,col+1,ans,move+'R',mat,n,vis);
            vis[row][col]=0;
        }
        //up
        if(row-1>=0 && mat[row-1][col]==1 && !vis[row-1][col]){
            vis[row][col]=1;
            f(row-1,col,ans,move+'U',mat,n,vis);
            vis[row][col]=0;
        }
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>ans;
        if (mat[0][0]==1) f(0,0,ans,"",mat,n,vis);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends