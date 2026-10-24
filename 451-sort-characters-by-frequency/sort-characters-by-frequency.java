class Solution {
    public String frequencySort(String s) {
        char[] arr = s.toCharArray();
        HashMap<Character, Integer> map = new HashMap<>();

        for(int i=0; i<arr.length; i++){
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }

        PriorityQueue<Character> pq = new PriorityQueue<>((a,b) -> map.get(b) - map.get(a));

        pq.addAll(map.keySet());

        StringBuilder sb = new StringBuilder();
        while(!pq.isEmpty()){
            char ch = pq.poll();

            for(int i=0; i<map.get(ch); i++){
                sb.append(ch);
            }
        }

        return sb.toString();

    }
}