// class Solution {
//     class Pair {
//         int node, wt;

//         Pair(int node, int wt) {
//             this.node = node;
//             this.wt = wt;
//         }
//     }

//     public int minCostConnectPoints(int[][] points) {
//         int n = points.length;

//         boolean[] vis = new boolean[n];

//         PriorityQueue<Pair> pq = new PriorityQueue<>(
//             (a, b) -> Integer.compare(a.wt, b.wt)
//         );

//         pq.add(new Pair(0, 0));

//         int sum = 0;
//         int count = 0;

//         while (!pq.isEmpty() && count < n) {
//             Pair p = pq.poll();

//             int node = p.node;
//             int wt = p.wt;

//             if (vis[node]) continue;

//             vis[node] = true;
//             sum += wt;
//             count++;

//             for (int i = 0; i < n; i++) {
//                 if (!vis[i]) {
//                     int dist = Math.abs(points[node][0] - points[i][0])
//                              + Math.abs(points[node][1] - points[i][1]);

//                     pq.add(new Pair(i, dist));
//                 }
//             }
//         }

//         return sum;
//     }
// }

class Solution {

    class Edge {
        int u, v, wt;

        Edge(int u, int v, int wt) {
            this.u = u;
            this.v = v;
            this.wt = wt;
        }
    }

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

    public int minCostConnectPoints(int[][] points) {
        int n = points.length;

        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        ArrayList<Edge> edges = new ArrayList<>();

        // Generate all possible edges
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int wt = Math.abs(points[i][0] - points[j][0])
                       + Math.abs(points[i][1] - points[j][1]);

                edges.add(new Edge(i, j, wt));
            }
        }

        // Sort edges by weight
        edges.sort((a, b) -> Integer.compare(a.wt, b.wt));

        int sum = 0;
        int count = 0;

        for (Edge e : edges) {
            int pu = find(e.u);
            int pv = find(e.v);

            if (pu != pv) {
                union(pu, pv);
                sum += e.wt;
                count++;
            }

            if (count == n - 1) break;
        }

        return sum;
    }
}
