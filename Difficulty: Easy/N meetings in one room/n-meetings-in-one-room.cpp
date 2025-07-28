class Solution {
    //create a data object ->start,end,position
    struct data{
        int start;
        int end;
        int pos;
    };
    static bool comp(data val1,data val2){
        return val1.end<val2.end;
    }
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<data> arr(n);
        //enter the elemets 
        for(int i=0;i<n;i++){
            arr[i].start=start[i];
            arr[i].end=end[i];
            arr[i].pos=i+1;
        }
        sort(arr.begin(),arr.end(),comp);
        //start cnt now
        int cnt=1;
        int freetime=arr[0].end;
        for(int i=1;i<n;i++){
            if(arr[i].start>freetime){
                cnt++;
                freetime=arr[i].end;
                
            }
                
        }
        
        return cnt;
    }
};