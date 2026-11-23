class Solution {
    public int numSplits(String s) {

        int ans = 0;
        HashMap<Character, Integer> map1 = new HashMap<>(); 
        HashMap<Character, Integer> map2 = new HashMap<>();

        for(char ch : s.toCharArray()){
            map1.put(ch, map1.getOrDefault(ch, 0) + 1);
        }

        for(char ch : s.toCharArray()){
            map2.put(ch, map1.getOrDefault(ch, 0) + 1);
            map1.put(ch, map1.getOrDefault(ch, 0) - 1);

            if(map1.get(ch) == 0){
                map1.remove(ch);
            }

            if(map1.size() == map2.size()){
                ans++;
            }
        }
        return ans;
    }
}