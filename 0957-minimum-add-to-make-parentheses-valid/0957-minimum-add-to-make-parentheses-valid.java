class Solution {
    public int minAddToMakeValid(String s) {
        int open=0;
        //empty string is a valid parenthesis
        int res=0;
        for(char ch:s.toCharArray()){
            if(ch=='('){
                open++;
            }else{
                if(open==0)
                    res+=1;
                open=Math.max(open-1,0);
            }
        }
        return res+open;
    }
}