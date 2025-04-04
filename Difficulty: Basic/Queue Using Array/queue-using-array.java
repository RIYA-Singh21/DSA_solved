//{ Driver Code Starts
import java.util.Scanner;

class GfG
{
	public static void main(String args[])
	{
		 Scanner sc = new Scanner(System.in);
		 int t=sc.nextInt();
		 while(t>0)
		 {
			MyQueue obj = new MyQueue();
			int Q = sc.nextInt();
			while(Q>0)
			{
				int QueryType = 0;
				QueryType = sc.nextInt();
				if(QueryType == 1)
				{
					int a = sc.nextInt();
					
					obj.push(a);
					
				}else if(QueryType == 2)
				{
				System.out.print(obj.pop()+" ");
				}
				Q--;
			}
			System.out.println("");
			t--;
		 
System.out.println("~");
}
	}
}




// } Driver Code Ends

class MyQueue {

    int front, rear,cursize;
	int arr[] = new int[100005];

    MyQueue()
	{
		front=0;
		rear=0;
		cursize=0;
	}
	
	//Function to push an element x in a queue.
	void push(int x)
	{
	    if(cursize==arr.length){
	        return;
	    }
	    //since front and rear are starting from 0 , no need to increment them
	   //if(cursize==0){
	     //  front++; rear++;
	   //}else{
	   //rear=(rear+1)%arr.length; this is first when front and rear start from -1
	   //}
	   cursize++;
	   arr[rear]=x;
	   rear=(rear+1)%arr.length; //when front starts from 0
	
	} 

    //Function to pop an element from queue and return that element.
	int pop()
	{
	    if(cursize==0){
	        return -1;
	    }
	    int el=arr[front];
	    //if(cursize==1){
	      //  front=-1;
	        //rear=-1;
	    //}
	    front=(front+1)%arr.length;
	    cursize--;
	    return el;
	
	} 
}




