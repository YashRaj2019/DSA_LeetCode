class Solution {
    public String longestPalindrome(String s) {
        int start = 0, maxLen = 1;
        for(int i=0; i<s.length(); i++){
            for(int j=i; j<s.length(); j++){
                if(isPal(s, i, j) && (j - i + 1) > maxLen){
                    start = i;
                    maxLen = j -i + 1;
                }
            }
        }
        return s.substring(start, start+maxLen);
    }

    boolean isPal(String s, int left, int right){

        if(left >= right){
            return true;
        }

        if(s.charAt(left) != s.charAt(right)){
            return false;
        }

        return isPal(s, left+1, right-1);
    }
}