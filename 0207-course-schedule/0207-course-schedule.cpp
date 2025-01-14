class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisite) {
        //usin' topo sort :BFS
        vector<int>adj[numCourses];
       //for(int i=0;i<prerequisite.size();i++){
        //int course=prerequisite[i][0];
        //int prereq=prerequisite[i][1];
        for(auto it:prerequisite){
        adj[it[1]].push_back(it[0]);
       }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i])
                indegree[it]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if (cnt==numCourses) return true;
        return false;
    }
};