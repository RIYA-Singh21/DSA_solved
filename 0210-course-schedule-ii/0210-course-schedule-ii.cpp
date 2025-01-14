class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>indegree(numCourses,0);
        queue<int>q;
        vector<int>adj[numCourses];
        //adj list; make graph
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        //calculate indegree
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i])
            indegree[it]++;
        }
        //push in q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(cnt==numCourses)
        return ans;
        else return {};
    }
};