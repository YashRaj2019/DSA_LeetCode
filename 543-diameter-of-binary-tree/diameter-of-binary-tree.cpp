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
// class Solution {
// public:
//     // helper function
//     int height(TreeNode *root){
//         if(root == NULL){
//             return 0;
//         }

//         return 1 + max(height(root->left), height(root->right));
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root == NULL){
//             return 0;
//         }

//         int leftDiameter = diameterOfBinaryTree(root->left);
//         int rightDiameter = diameterOfBinaryTree(root->right);
//         int currDiameter = height(root->left) + height(root->right);

//         return max(currDiameter, max(leftDiameter, rightDiameter));
//     }
// };

// method 2 : 

class Solution {
public:
    int ans = 0;
    // helper function
    int height(TreeNode *root){
        if(root == NULL){
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        ans = max(ans, (leftHeight + rightHeight));

        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};