class StockSpanner {
//optimal approach using stk to find the previous greater element
 Stack<Pair<Integer,Integer>>st; 
 int ind=-1;
    public StockSpanner() {
        st=new Stack<>();
        ind=-1;
    }
    
    public int next(int price) {
        ind+=1;
        //java has peek not top first=getKey sec=getValue
        while(!st.isEmpty() && st.peek().getKey()<=price){
            st.pop();
        }
        int ans=ind-(st.isEmpty()?-1:st.peek().getValue());
        st.push(new Pair<>(price,ind));
        return ans;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */