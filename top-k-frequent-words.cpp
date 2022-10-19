//question link - https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> freq;
        map<int, vector<string>, greater<int>> mapper;
        vector<string> ans;
        for(int i=0; i<words.size(); i++) {
            freq[words[i]] += 1;
        }
        
        for(auto it=freq.begin(); it!=freq.end(); it++) {
            mapper[it->second].push_back(it->first);
        }
        
        for(auto it=mapper.begin(); it!=mapper.end(); it++) {
            sort(it->second.begin(), it->second.end());
            for(int j=0; j<it->second.size(); j++) {
                ans.push_back(it->second[j]);
                if(ans.size() == k) {
                    break;
                }
            }
            if(ans.size() == k) {
                break;
            }
        }
        return ans;
    }
};