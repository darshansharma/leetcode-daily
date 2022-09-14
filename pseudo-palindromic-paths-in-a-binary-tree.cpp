// question link - https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/submissions/

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
    vector<int> checker;
    int count = 0;
    map<int, int> freq;
    int depth = 0;
    int maxDepth = 0;
    void checkForPalindrome() {
        int oddCounter = 0;
        int evenCounter = 0;
        int nElements = 0;
        for(auto it=freq.begin(); it!=freq.end(); it++) {
            nElements += it->second;
        }
        if(nElements %2 ==0) {
            for(auto it=freq.begin(); it!=freq.end(); it++) {
                if(it->second %2 == 0) {
                    continue;
                } else {
                    evenCounter++;
                    break;
                }
            }
            if(evenCounter == 0) {
                count++;
            }
        } else {
            for(auto it=freq.begin(); it!=freq.end(); it++) {
                if(it->second %2 == 0) {
                    continue;
                } else {
                    oddCounter  += 1;
                }
            }
            if(oddCounter == 1) {
                count++;
            }
        }
    }
    
    void traverse(TreeNode* root, int section, TreeNode* sibling){
        if(root==NULL) {
            if(maxDepth < depth) {
                maxDepth = depth;
            }
            if(section == 1 && sibling == NULL) {
                checkForPalindrome();    
            }
            return;
        }
        freq[root->val] += 1;
        depth++;
        traverse(root->left, 0, root->right);
        traverse(root->right, 1, root->left);
        freq[root->val] -= 1;
        depth--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root->right == NULL && root->left == NULL) {
            return 1;
        }
        traverse(root, 0, root->left);
        return count;
    }
};