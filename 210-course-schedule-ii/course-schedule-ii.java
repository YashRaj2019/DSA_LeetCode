
class Solution {

    public boolean isCycleDFS(int src, boolean[] vis, boolean[] recPath, int[][] edges) {
        vis[src] = true;
        recPath[src] = true;

        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (src == v) {
                if (!vis[u]) {
                    if (isCycleDFS(u, vis, recPath, edges)) {
                        return true;
                    }
                }
                else if (recPath[u]) {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    void topo(int src, boolean[] vis, int[][] edges, Stack<Integer> s) {
        vis[src] = true;

        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (src == v) {
                if (!vis[u]) {
                    topo(u, vis, edges, s);
                }
            }
        }

        s.push(src);
    }

    public int[] findOrder(int n, int[][] edges) {

        boolean[] vis = new boolean[n];
        boolean[] recPath = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (isCycleDFS(i, vis, recPath, edges)) {
                    return new int[0];
                }
            }
        }

        vis = new boolean[n];
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                topo(i, vis, edges, s);
            }
        }

        int[] ans = new int[n];
        int i = 0;

        while (!s.isEmpty()) {
            ans[i++] = s.pop();
        }

        return ans;
    }
}
