class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        int ans = 0;
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        
        // Build adjacency list
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        // Topological sort using Kahn's algorithm
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int processed = 0;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            processed++;
            
            // Increment count for current node's color
            cnt[curr][colors[curr] - 'a']++;
            ans = max(ans, cnt[curr][colors[curr] - 'a']);
            
            // Process all neighbors
            for(int neighbor : graph[curr]) {
                indegree[neighbor]--;
                
                // Update color counts for neighbor
                for(int j = 0; j < 26; j++) {
                    cnt[neighbor][j] = max(cnt[neighbor][j], cnt[curr][j]);
                }
                
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return processed == n ? ans : -1;
    }
};