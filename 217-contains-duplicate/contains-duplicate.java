class Solution {
    public boolean containsDuplicate(int[] nums) {
        // HashMap<Integer, Integer> map = new HashMap<>();

        // for(int ele : nums){
        //     map.put(ele, map.getOrDefault(ele, 0) + 1);

        //     if(map.get(ele) >=2 ){
        //         return true;
        //     }
        // }

        // return false;

        HashSet<Integer> set = new HashSet<>();

        for(int ele : nums){
            if(set.contains(ele)){
                return true;
            }

            set.add(ele);
        }
        return false;
    }
}