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
                else if(recPath[v]){ // back edge ->cycle
                        return true;
                    }
                
            }
        }
        recPath[src] = false;
        return false;
    }  

    void topoOrder(int src, vector<bool> &visited, stack<int> &s, vector<vector<int>>& edges){
        visited[src] = true;

        for(int i=0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src){ // here if u = src node the v = visited node
                if(!visited[v]){
                    topoOrder(v, visited, s, edges);
                }
                
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) { // n = numCources = no of vertices, prerequisites = directed edges
        vector<bool> visited(n, false);
        vector<bool> recPath(n, false);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(isCycleDFS(i, visited, recPath, edges)){
                    return ans;
                }
            }
        }

        // Topological sorted Order -DAG

        stack<int>s;
        visited.assign(n, false);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                topoOrder(i, visited, s, edges);
            }
        }

        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;

    }
};