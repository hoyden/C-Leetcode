/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * 
 * Output: [1,3,2]
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode* > st;
        vector<int> ret;
        while(root != NULL || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root -> left;
            }
            root = st.top();
            ret.push_back(root -> val);
            st.pop();
            root = root -> right;
        }
        return ret;
    }
};