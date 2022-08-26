class Solution {
public:
    
    
    int getNumberLength(int val) {
        int x = 10;
        int len = 0;
        while(val > 0) {
            val /= x;
            len++;
        }
        return len;
    }
    
    bool reorderedPowerOf2(int n) {
        int i=0;
        int power = 2;
        vector<int> powers;
        unordered_map<int, vector<int>> umap;
        int lengthOfInput = getNumberLength(n);
        vector<int>cs;
        for(int i=0; i<10; i++) {
            cs.push_back(0);
        }
        int current = n;
        for(int i=0; i<lengthOfInput; i++) {
            while(current > 0) {
                int x = current%10;
                cs[x] += 1;
                current /= 10;
            }
        }
        while(1) {
            if(i == 31) break;
            powers.push_back(pow(2,i));
            i++;
        }
        
        for(int i=0; i<powers.size(); i++) {
            umap[getNumberLength(powers[i])].push_back(powers[i]);
        }
        
        for(int i=0; i<umap[lengthOfInput].size(); i++) {
            int current = umap[lengthOfInput][i];
            vector<int> checker = cs;
            bool flag = true;
            while(current > 0) {
                int x = current%10;
                checker[x] -= 1;
                current /= 10;
            }
            for(int i=0; i<10; i++) {
                if(checker[i] != 0) {
                    flag = false;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};