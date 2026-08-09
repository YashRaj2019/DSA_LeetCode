/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode* root, int &ans){
        if(!root){
            return 0;
        }

        // get best path from left and right
        int left = max(0, solve(root->left, ans));
        int right = max(0, solve(root->right, ans));

        // path passing through the current node
        int curr = root->val + left + right;

        // update overall answer
        ans = max(ans, curr);

        // return the path that can be extended by parents
        return root->val + max(left, right); 
    }
    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};