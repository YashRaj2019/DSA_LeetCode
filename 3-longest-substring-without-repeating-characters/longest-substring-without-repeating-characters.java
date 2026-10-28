class Solution {
    public int lengthOfLongestSubstring(String s) {

        // HashSet<Character> set = new HashSet<>();
        // int left = 0, right = 0, maxLen = 0;

        // while(right < s.length()){
        //     char ch = s.charAt(right);

        //     if(set.contains(ch)){
        //         set.remove(s.charAt(left));
        //         left++;
        //     }
        //     else{
        //         set.add(ch);
        //         maxLen = Math.max(maxLen, right - left + 1);
        //         right++;
        //     }
        // }
        // return maxLen;

        int left = 0, maxLen = 0;
        int[] freq = new int[128];

        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            freq[ch]++;

            while (freq[ch] > 1) {
                freq[s.charAt(left)]--;
                left++;
            }

            maxLen = Math.max(maxLen, right - left + 1);
        }

        return maxLen;
    
    }
}