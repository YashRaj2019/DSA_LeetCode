class Solution {
    int[] parent;
    int[] rank;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } 
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } 
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;

        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    union(i, j);
                }
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                count++;
            }
        }

        return count;
    }
}

// class Solution {

//     void dfs(int i, int[][] adj, boolean[] vis){
//         vis[i] = true;

//         for(int j=0; j<adj[i].length; j++){
//             if(adj[i][j] == 1 && !vis[j]){
//                 dfs(j, adj, vis);
//             }
//         }
//     }

//     public int findCircleNum(int[][] isConnected) {
//         int count = 0;
//         int n = isConnected.length; // n x n

//         boolean[] vis = new boolean[n];

//         for(int i=0; i<n; i++){
//             if(!vis[i]){
//                 dfs(i, isConnected, vis);
//                 count++;
//             }
//         }
//         return count;
//     }
// }