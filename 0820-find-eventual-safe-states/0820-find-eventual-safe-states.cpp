class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& currPath, vector<int>& safe) {
        visited[node] = 1;
        currPath[node] = 1;

        for(int nbr : adj[node]) {
            if(!visited[nbr]) {
                if(dfs(nbr, adj, visited, currPath, safe)) 
                    return true; 
            } 
            else if(currPath[nbr] == 1) {
                return true; 
            }
        }

        currPath[node] = 0;
        safe[node] = 1;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> visited(v, 0), currPath(v, 0), safe(v, 0);

        for(int i=0;i<v;i++) {
            if(!visited[i]) {
                dfs(i, graph, visited, currPath, safe);
            }
        }

        vector<int> ans;
        for(int i=0;i<v;i++) {
            if(safe[i]) ans.push_back(i); 
        }
        return ans;
    }
};
