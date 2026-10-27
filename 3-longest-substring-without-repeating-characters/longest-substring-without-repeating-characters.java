class Solution {
    public int lengthOfLongestSubstring(String s) {

        HashSet<Character> set = new HashSet<>();
        int left = 0, right = 0, maxLen = 0;

        while(right < s.length()){
            char ch = s.charAt(right);

            if(set.contains(ch)){
                set.remove(s.charAt(left));
                left++;
            }
            else{
                set.add(ch);
                maxLen = Math.max(maxLen, right - left + 1);
                right++;
            }
        }
        return maxLen;
    }
}