class Solution {
    class Pair {
        int node, wt;

        Pair(int node, int wt) {
            this.node = node;
            this.wt = wt;
        }
    }

    public int minCostConnectPoints(int[][] points) {
        int n = points.length;

        boolean[] vis = new boolean[n];

        PriorityQueue<Pair> pq = new PriorityQueue<>(
            (a, b) -> Integer.compare(a.wt, b.wt)
        );

        pq.add(new Pair(0, 0));

        int sum = 0;
        int count = 0;

        while (!pq.isEmpty() && count < n) {
            Pair p = pq.poll();

            int node = p.node;
            int wt = p.wt;

            if (vis[node]) continue;

            vis[node] = true;
            sum += wt;
            count++;

            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    int dist = Math.abs(points[node][0] - points[i][0])
                             + Math.abs(points[node][1] - points[i][1]);

                    pq.add(new Pair(i, dist));
                }
            }
        }

        return sum;
    }
}