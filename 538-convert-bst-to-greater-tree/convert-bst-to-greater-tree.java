/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    public void inOrder(TreeNode root, ArrayList<TreeNode> list){
        if(root == null){
            return;
        }

        inOrder(root.left, list);
        list.add(root);
        inOrder(root.right, list);

    }

    public TreeNode convertBST(TreeNode root) {
        ArrayList<TreeNode> list = new ArrayList<>();
        inOrder(root, list);

        Collections.reverse(list);

        int sum = 0;

        for(int i=0; i<list.size(); i++){
            sum += list.get(i).val;
            list.get(i).val = sum;
        }

        return root;

    }
}