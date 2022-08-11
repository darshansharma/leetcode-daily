

// problem link - https://leetcode.com/problems/poor-pigs/

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
        }
};


// Based on quantum states concept
// hard question