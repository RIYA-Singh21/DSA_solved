class Solution {
public:
//using priority queue: min heap
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
            return false;
        //declaring min heap
        priority_queue<int,vector<int>,greater<int>>pq;
        //store the freq in a map
        unordered_map<int,int>mpp;
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }
        //store the elements in min heap
        for(auto &i : mpp){
            //push the element
            pq.push(i.first);
        }

        while(!pq.empty()){
            int ele=pq.top();
            for(int i=0;i<groupSize;i++){
                    if(mpp[ele+i]==0) 
                        return false;
                
                    mpp[ele+i]--;
                    if(mpp[ele+i]==0){
                        if(ele+i!=pq.top())return false; 
                        pq.pop();
                }
            }
        }
     return true;   
    }
};