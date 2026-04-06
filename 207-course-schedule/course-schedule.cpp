class Solution {
public:

    bool isCycleDFS(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &edges){
        visited[src] = true;
        recPath[src] = true;

        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src){ // here if u = src node the v = visited node
                if(!visited[v]){
                    if(isCycleDFS(v, visited, recPath, edges)){
                        return true;
                    }
                }
                else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }


    bool canFinish(int n, vector<vector<int>>& edges) { // n = numCources = no of vertices, prerequisites = directed edges
        vector<bool> visited(n, false);
        vector<bool> recPath(n, false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(isCycleDFS(i, visited, recPath, edges)){
                    return false;
                }
            }
        }
        return true;
    }
};