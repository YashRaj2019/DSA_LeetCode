class Solution {
public:

    void DFS(vector<vector<int>>&isConnected, vector<bool>&visited, int node){
        
        if(visited[node]){
            return;
        }

        visited[node] = 1;
        
        for(int i=0; i<isConnected[node].size();i++){
            if(isConnected[node][i]){
                DFS(isConnected, visited ,i);
            }
        };
        
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // code here
        
        int V = isConnected.size();
        int count = 0;
        vector<bool>visited(V, 0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                DFS(isConnected, visited, i);
            }
        }
        return count;
    }
};