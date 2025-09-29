class Solution {
public:
//using ordered map
//TC: O(nlogn)+O(n*groupSize)
//SC: O(hands.size())
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //if the number of ele are not divisible by grpSize then ret false
        if(hand.size()%groupSize!=0)
            return false;
        map<int,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++; //O(nlogn)->ordered map
        }
        while(!mp.empty()){//O(n*groupSize)
            //store the first ele of the group
            int curr=mp.begin()->first;//first:ele second : freq
            //no. of ele in the group = groupSize so loop through the groupSize
            for(int i=0;i<groupSize;i++){
                //if ele is not present 
                if(mp[curr+i]==0)
                    return false;
                mp[curr+i]--;
                //if the element's freq ==0 remove it from the map
                if(mp[curr+i]<1)
                    mp.erase(curr+i);
            }

        }
        return true;
   }

};