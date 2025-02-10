//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node *root){
        if(root && root->left==NULL && root->right==NULL)return true;
        return false;
    }
    void addleftboundary(Node*root,vector<int>&ans){
        Node*curr=root->left;
        while(curr){
            if(!isLeaf(curr))ans.push_back(curr->data);
            if(curr->left) curr=curr->left;
            else curr=curr->right;
        }
    }
    void addleaves(Node*root,vector<int>&ans){
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left)addleaves(root->left,ans);
        if(root->right)addleaves(root->right,ans);
    }
    //in right coundary add the elements in reverse order 
    void addrightboundary(Node*root,vector<int>&ans){
        Node*curr=root->right;
        vector<int>temp;
        while(curr){
            if(!isLeaf(curr))temp.push_back(curr->data);
            if(curr->right) curr=curr->right;
            else curr=curr->left;
        }
        int n=temp.size();
        for(int i=n-1;i>=0;i--){
            ans.push_back(temp[i]);
        }
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        if(!isLeaf(root))ans.push_back(root->data);
        
        addleftboundary(root,ans);
        addleaves(root,ans);
        addrightboundary(root,ans);
        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends