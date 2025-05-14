class Solution {
    //recursion
    public List<String> generateParenthesis(int n) {
        //open=close=n
        //only add ) if open>close or if open==close add ( 
        //output = open==close==n
        List<String>ans=new ArrayList<>();
        solve("",0,0,n,ans);
        return ans;
        
    }
    private void solve(String curr, int open,int close,int total, List<String>ans ){
        if(curr.length()==total*2){
            ans.add(curr);
            return;
        }
        if(open<total)
            solve(curr+"(",open+1,close,total,ans);
        if(close<open)
            solve(curr+")",open,close+1,total,ans);
    }
}