class Solution {
    public int minEatingSpeed(int[] piles, int h) {

        int low = 1;
        int high = Arrays.stream(piles).max().getAsInt();

        while(low <= high){
            int mid = low + (high - low) / 2;
            
            long hours = 0;
            // for(int pile : piles){
            //     hours += (pile + mid - 1) / mid; // here pile represents the no of banana in each piles
                //means each index represnts a plile and hoe much banana it have how much banana and mid represents the eating speed 

            // or
            for(int pile : piles){
                hours += pile / mid;

                if(pile % mid != 0){
                    hours++;
                }
            }

            if(hours <= h){
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
}