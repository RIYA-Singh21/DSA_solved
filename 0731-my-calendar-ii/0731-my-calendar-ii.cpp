//make a constructor
class Event{
public:
    int start;
    int end;
    Event (int s,int e){
        start=s;
        end=e;
    }
};
class MyCalendarTwo {
public:
        vector<Event>overlapping;
        vector<Event>bookings;
    MyCalendarTwo() {
        //make 2 arrays to store overlapping intervals and if not triple overlapped then store
        //the elements in bookings array
    }
    
    bool book(int startTime, int endTime) {
        for(Event e: overlapping){
            if(isOverlap(e,startTime,endTime)){
                return false;
            }
        }
        for(Event e:bookings){
            if(isOverlap(e,startTime,endTime)){
                overlapping.push_back(getOverlapEvent(e,startTime,endTime));
            }
        }
        bookings.push_back(Event(startTime,endTime));
        return true;
    }
    bool isOverlap(Event e,int start, int end){
        return max(e.start,start)<min(e.end,end);
     }

    Event getOverlapEvent(Event e, int start, int end){
        return Event(max(e.start,start),min(e.end,end));
        }

};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */