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
    map <int, map<int, vector<int>>> umap;
    int index = 0;
    void traverse(TreeNode* root, int x, int y) {
        if(root == NULL) {
            return;
        }
        umap[x][y].push_back(root->val);
        
        traverse(root->left, x+1, y-1);
        traverse(root->right, x+1, y+1);
    }
        
    int get_second( pair<int, int> i ){ return i.second; }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map <int, vector<int>> holder;
        traverse(root, index, index);
        for (const auto& [k1, v1] : umap){
            for (const auto& [k2, v2] : v1){
                sort(umap[k1][k2].begin(), umap[k1][k2].end());
                for(int i=0; i<v2.size(); i++) {
                    // std::cout << "[" << k1 << "][" << k2 << "]= " << v2[i] << std::endl;
                    holder[k2].push_back(v2[i]);
                }
                
            }
            
        }
        
        for(auto it=holder.begin(); it!=holder.end(); it++) {
            res.push_back(it->second);
        }
        
        return res;
    }
};