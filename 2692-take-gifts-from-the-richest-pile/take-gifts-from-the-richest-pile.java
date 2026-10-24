class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int ele : gifts){
            pq.add(ele);
        }

        while(k > 0){
            int max = pq.remove();
            int remain = (int) Math.sqrt(max);
            pq.add(remain);
            k--;
        }

        long sum = 0;
        while(!pq.isEmpty()){
            sum += pq.remove();
        }

        return sum;
    }
}