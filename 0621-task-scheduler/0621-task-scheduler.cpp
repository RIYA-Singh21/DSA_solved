class Solution {
public:
//using priority queue (max heap)
    int leastInterval(vector<char>& tasks, int n) {
        //to store the freq of char
        vector<int>mp(26,0);
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]-'A']++;
        }
        int time=0;
        //store the elements in Pq (max heap)
        priority_queue<int>pq;
        for(int i=0;i<mp.size();i++){
            if(mp[i]>0)
                pq.push(mp[i]);
        }
        //till !pq.empty
        while(!pq.empty()){
            //take a temp vector to store the adjacent elements 
            vector<int>temp;
            //at a time we can only implement n+1 tasks
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int f=pq.top();
                    pq.pop();
                    f--;
                    temp.push_back(f);
                }
            }
            for(int &f:temp){
                if(f>0)
                    pq.push(f);
            }
        if(!pq.empty()){
            time+=n+1;
        }else time+=temp.size();
        }
        return time;

    }
};