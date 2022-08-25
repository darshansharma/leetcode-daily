class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map <char, int> umap;
        for(int i=0; i<magazine.length(); i++) {
            umap[magazine[i]] += 1;
        }
        
        for(int i=0; i<ransomNote.length(); i++) {
            if(umap[ransomNote[i]] == 0) {
                return false;
            }
            umap[ransomNote[i]] -= 1;
        }
        return true;
    }
};