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
    
    // method 2: using dfs (mostly asked in interview) : teverse right -> left
    void dfs(TreeNode* root, int level, vector<int> &ans){
        if(root == NULL){
            return;
        }
        
        if(level == ans.size()){
            ans.push_back(root->val);
        }

        dfs(root->right, level+1 , ans);
        dfs(root->left, level+1, ans);

    }

    vector<int> rightSideView(TreeNode* root) { 
       vector<int>ans;
       dfs(root, 0, ans);
       return ans;
    }
};


// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) { // bfs, using level order travesal
//         vector<int>ans;

//         if(root == NULL){
//             return ans;
//         }

//         queue<TreeNode*>q;
//         q.push(root);

//         while(!q.empty()){
//             int size = q.size();

//             for(int i=0; i<size; i++){
//                 TreeNode* curr = q.front();
//                 q.pop();

//                 if(i == size - 1){
//                     ans.push_back(curr->val);
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