
// question link - https://leetcode.com/problems/validate-binary-search-tree

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
    vector<int>nodes;
    TreeNode* parentRootNode;
    bool flag = true;
public:
    
    int inOrderTraversal(TreeNode* root){
        if (root == NULL) return NULL;
        // cout<<"root = "<<root->val<<endl;
        if (root->left == NULL && root->right == NULL) {
            return root->val;
        }
        int x = inOrderTraversal(root->left);
        if (x != NULL) {
            // cout<<"Time to push to array = "<<x<<endl;
            nodes.push_back(x);
        }
        // cout<<"Time to push to array = "<<root->val<<endl;
        nodes.push_back(root->val);
        x = inOrderTraversal(root->right);
        if (x != NULL) {
            // cout<<"Time to push to array = "<<x<<endl;
            nodes.push_back(x);
            
        }
        return NULL;
    }
    
    bool isValidBST(TreeNode* root) {
        inOrderTraversal(root);
        if (unique(nodes.begin(), nodes.end()) == nodes.end()) {
            return is_sorted(begin(nodes), end(nodes));    
        }
        return false;
        
    }
};