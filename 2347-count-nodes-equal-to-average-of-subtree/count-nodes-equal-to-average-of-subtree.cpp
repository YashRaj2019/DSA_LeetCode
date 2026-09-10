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

    int sum(TreeNode* root){

        if(!root){
            return 0;
        }

        return root->val + sum(root->left) + sum(root->right);
    }

    int count(TreeNode* root){
        if(!root){
            return 0;
        }

        return 1 + count(root->left) + count(root->right);
    }

    int ans = 0;

    void solve(TreeNode* root){

        if(!root){
            return;
        }

        int s = sum(root);
        int c = count(root);

        if(s / c == root->val){
            ans++;
        }

        solve(root->left);
        solve(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};