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
    
    int ans = 0;
    int maxDepth = -1;

    void dfs(TreeNode* root, int depth){
        if(!root){
            return;
        }

        if(depth > maxDepth){
            maxDepth = depth;
            ans = root->val;
        }

        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root) { 
        dfs(root, 0);
        return ans;
    }
};
// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) { // method 1: using bfs

//         queue<TreeNode*>q;
//         q.push(root);

//         int ans = root->val;

//         while(!q.empty()){
//             int size = q.size();

//             for(int i=0; i<size; i++){
//                 TreeNode* curr = q.front();
//                 q.pop();

//                 if(i == 0){
//                     ans = curr->val;
//                 }

//                 if(curr->left){
//                     q.push(curr->left);
//                 }

//                 if(curr->right){
//                     q.push(curr->right);
//                 }
//             }
//         }
//         return ans;
//     }
// };