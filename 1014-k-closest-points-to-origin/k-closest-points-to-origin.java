// class Solution {
//     public int[][] kClosest(int[][] points, int k) {
//         PriorityQueue<int[]> pq = new PriorityQueue<>(  // max heap : method 1
//             (a, b) -> Integer.compare(
//                 b[0]*b[0] + b[1]*b[1],
//                 a[0]*a[0] + a[1]*a[1]
//             )
//         );

//         for(int[] point : points){
//             pq.add(point);

//             if(pq.size() > k){
//                 pq.remove();
//             }
//         }

//         int[][] ans = new int[k][2];

//         for(int i=0; i<k; i++){
//             ans[i] = pq.remove();
//         }

//         return ans;
//     }
// }


class Triplet implements Comparable<Triplet>{
    int dist;
    int x;
    int y;

    Triplet(int dist, int x, int y){
        this.dist = dist;
        this.x = x;
        this.y = y;
    }

    public int compareTo(Triplet t){
        return this.dist - t.dist;
    }
}


class Solution {
    public int[][] kClosest(int[][] points, int k) {
        // kth smallest distance max heap : Method 2

        PriorityQueue<Triplet> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int[] point : points){
            int x = point[0], y = point[1];
            int dist = x*x + y*y;

            pq.add(new Triplet(dist, x, y));

            if(pq.size() > k){
                pq.remove();
            }
        }

        int[][] ans = new int[k][2];
        for(int i=0; i<k; i++){
            Triplet top = pq.remove();
            ans[i][0] = top.x;
            ans[i][1] = top.y;
        }
        return ans;
    }
}