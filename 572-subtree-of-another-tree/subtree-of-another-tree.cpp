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
    bool isIdentical(TreeNode* t1, TreeNode* t2){

        if(!t1 || !t2){
            return t1 == t2;
        }

        return (t1->val == t2->val) && isIdentical(t1->left, t2->left) && isIdentical(t1->right, t2->right); 
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!root || !subRoot){
            return root == subRoot;
        }

        if(root->val == subRoot->val && isIdentical(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};