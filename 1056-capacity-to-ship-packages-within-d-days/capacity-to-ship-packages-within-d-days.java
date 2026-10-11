class Solution {
    public int shipWithinDays(int[] weights, int days) {

        int low = Arrays.stream(weights).max().getAsInt();
        int high = Arrays.stream(weights).sum();

        while(low <= high){
            int mid = low + (high - low)/2;

            int day = 1;
            int sum = 0;

            for(int weight : weights){
                if(sum + weight > mid){
                    day++;
                    sum = weight;
                }
                else{
                    sum += weight;
                }
            }
            if(day <= days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
}