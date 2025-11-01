class StockSpanner {
//brute force
//using a dynamic list
    ArrayList<Integer>sp;
    public StockSpanner() {
        sp=new ArrayList<>();
    }
    
    public int next(int price) {
        sp.add(price);
        int cnt=1;
        //check from arr.size()-2 since the last element itself will be counted already
        //since cnt=1 initially
        for(int i=sp.size()-2;i>=0;i--){
            if(sp.get(i)<=price)
                cnt++;
            else  break;
        }
        return cnt;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */