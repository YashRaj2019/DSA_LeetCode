class Solution {

    public void solve(String str, int open, int close, int n, List<String> list){
        if(str.length() == 2 * n){
            list.add(str);
            return;
        }

        // Add '('
        if(open < n){
            solve(str + '(', open + 1, close, n, list);
        }

        // Add ')'
        if(close < open){
            solve(str + ')', open, close + 1, n, list);
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> list = new ArrayList<>();
        solve("", 0, 0, n, list);
        return list;
    }
}