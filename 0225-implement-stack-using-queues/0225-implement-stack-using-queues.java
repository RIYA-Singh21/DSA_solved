class MyStack {
    Queue<Integer>q=new LinkedList<>();
    int start,end,size;
    public MyStack() {
        start=-1;
        end=-1;
        size=0;
    }
    
    public void push(int x) {
        q.add(x);
        //2 elements 0-1 
        for(int i=0;i<q.size()-1;i++)
            q.add(q.remove());
        size++;
    }
    
    public int pop() {
        if(size==0)return -1;
        size--;
       return q.poll();
       
    }
    
    public int top() {
        if(size==0)return -1;
        return q.peek();
    }
    
    public boolean empty() {
        return (size==0);
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */