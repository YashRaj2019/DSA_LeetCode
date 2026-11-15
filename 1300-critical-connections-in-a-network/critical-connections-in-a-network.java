class Solution {
    int time = 1;
    void dfs(int node, int parent, ArrayList<ArrayList<Integer>> adj, boolean[] vis, int[] dis, int[] low, List<List<Integer>> ans){

        vis[node] = true;
        dis[node] = low[node] = time++;

        for(int ele : adj.get(node)){

            if(ele == parent){
                continue;
            }

            if(!vis[ele]){
                dfs(ele, node, adj, vis, dis, low, ans);

                low[node] = Math.min(low[node], low[ele]);

                // Bridge condition
                if(low[ele] > dis[node]){
                    ans.add(Arrays.asList(node, ele));

                    // ArrayList<Integer> list = new ArrayList<>(); this can be also done

                    // list.add(node);
                    // list.add(ele);

                    // ans.add(list);
                }
            }

            else{
                low[node] = Math.min(low[node], dis[ele]);
            }

        }

    }

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
        }

        for(int i=0; i<connections.size(); i++){
            int u = connections.get(i).get(0);
            int v = connections.get(i).get(1);

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        boolean[] vis = new boolean[n];

        int[] dis = new int[n];
        int[] low = new int[n];

        List<List<Integer>> ans = new ArrayList<>();

        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, dis, low, ans);
            }
        }
        return ans;
    }
}