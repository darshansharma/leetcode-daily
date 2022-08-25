
// Question - https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size = arr.size();
        int counter = 0;
        vector<pair<int, int>> frequencyCounter;
        unordered_map<int, int> umap;
        for(int i=0; i<size; i++) {
            umap[arr[i]] += 1;
        }
        
        for(auto it: umap) {
            frequencyCounter.push_back(make_pair(it.first, it.second));
        }
        
        sort(frequencyCounter.begin(), frequencyCounter.end(), [](const auto& x, const auto& y){return x.second > y.second;});
        int newSize = 0;
        for (auto it: frequencyCounter) {
            // std::cout << "(" << it.first << ", " << it.second << ") ";
            newSize += it.second;
            counter++;
            if (newSize >= size/2) {
                break;
            }
        }
        return counter;
    }
};