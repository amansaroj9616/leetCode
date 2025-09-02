class Solution {
public:

    int longestCycleLen=-1;

    void dfs(int cyclelen,int node,vector<int>& edges , vector<int>&visited,vector<int>&currPath){
        cyclelen++;
        currPath[node]=cyclelen;
        visited[node]=1;
        int nbr=edges[node];
        if(nbr!=-1){
            if(!visited[nbr]){
                dfs(cyclelen,nbr,edges,visited,currPath);
            }
            else if(currPath[nbr]!=0){
                int currCycleLen = currPath[node] - currPath[nbr] + 1;

                longestCycleLen=max( longestCycleLen , currCycleLen);


            }
        }
        currPath[node]=0;

    }
    int longestCycle(vector<int>& edges) {
        int numberNode=edges.size();
        vector<int>visited(numberNode,0);
        vector<int>currPath(numberNode,0);
        for(int i=0;i<numberNode;i++){
            if(visited[i]!=1)
            dfs(0,i,edges,visited,currPath);

        }
        return longestCycleLen;
        
    }
};