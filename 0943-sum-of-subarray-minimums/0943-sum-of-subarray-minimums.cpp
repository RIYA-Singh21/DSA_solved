class Solution {
public:
vector<int> findnse(vector<int>arr){
    int n=arr.size();
    vector<int>nse(n);
    stack<int> st;
    for(int i=n-1;i>-1;i--){
        while(!st.empty() && arr[st.top()]>=arr[i] )
        st.pop();
        nse[i]=st.empty()?n:st.top();
        //push the element
        st.push(i);
    }
    return nse;

}
vector<int> findpsee(vector<int>arr){
    //here the equal to and smallest both are considered
    int n=arr.size();
    vector<int>psee(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i] )
        st.pop();
        psee[i]=st.empty()?-1:st.top();
        //push the element
        st.push(i);
    }
    return psee;

}
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=findnse(arr);
        vector<int> psee=findpsee(arr);
        int n=arr.size();
        int sum=0; const int mod=1e9+7;
        for(int i=0;i<n;i++){
            int left= i-psee[i];
            int right=nse[i]-i;
            sum=(sum+(1LL*left*right*arr[i])%mod)%mod;
        }
    return sum;
    }
};