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
    int findBottomLeftValue(TreeNode* root) {

        // method 1
        // queue<TreeNode*>q;
        // q.push(root);

        // int ans = root->val;

        // while(q.size() > 0){
        //     int n  = q.size();

        //     for(int i=0; i<n; i++){
        //         TreeNode* curr = q.front();
        //         q.pop();

        //         // first node of this level
        //         if(i == 0){
        //             ans = curr->val;
        //         }

        //         if(curr->left){
        //             q.push(curr->left);
        //         }

        //         if(curr->right){
        //             q.push(curr->right);
        //         }
        //     }
        // }
        // return ans;

        // Method : 2 Optimized : (Right → Left BFS) : Push right first, then left, → Last processed node will be answer

        queue<TreeNode*>q;
        q.push(root);

        TreeNode* curr;

        while(q.size() > 0){
            curr = q.front();
            q.pop();

            if(curr->right){
                q.push(curr->right);
            }

            if(curr->left){
                q.push(curr->left);
            }
        }
        return curr->val;
    }
};