class Solution {
    public int findTheWinner(int n, int k) {
        // Queue<Integer> q = new LinkedList<>();

        // for(int i=1; i<=n; i++){
        //     q.add(i);
        // }

        // while(q.size() > 1){
        //     // remove and add k-1 element
        //     for(int i=1; i<k; i++){
        //         q.add(q.remove());
        //     }
        //     q.remove(); // kth will be removed
        // }
        // return q.peek();

        int winner = 0;

        for (int i = 1; i <= n; i++) {
            winner = (winner + k) % i;
        }

        return winner + 1;
    }
}