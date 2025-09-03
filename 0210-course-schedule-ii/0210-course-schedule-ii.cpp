class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>ans;
        for(auto &edges:prerequisites){
            graph[edges[1]].push_back(edges[0]);

        }    
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(graph[i].empty()) continue;
            for(int &x:graph[i]){
                indegree[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(int &x:graph[f]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};