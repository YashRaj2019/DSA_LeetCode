class Solution {
    public boolean isAnagram(String s, String t) {
        // if(s.length() != t.length()){
        //     return false;
        // }

        // char[] arr1 = s.toCharArray();
        // Arrays.sort(arr1);
        // s = new String(arr1);

        // char[] arr2 = t.toCharArray();
        // Arrays.sort(arr2);
        // t = new String(arr2);

        // return s.equals(t);

        if(s.length() != t.length()){
            return false;
        }

        int[] freq = new int[26];
        for(int i=0; i<s.length(); i++){
            freq[s.charAt(i) - 'a']++;
            freq[t.charAt(i) - 'a']--;
        }

        for(int n : freq){
            if(n != 0){
                return false;
            }
        }
        return true;
    }
}