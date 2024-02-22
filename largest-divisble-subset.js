// question link - https://leetcode.com/problems/largest-divisible-subset/description
// difficulty - hard
// 


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var largestDivisibleSubset = function(nums) {
    const S = new Map();
    S.set(-1, new Set());
    nums.sort((a, b) => a - b);

    nums.forEach(x => {
        let maxSubset = new Set();
        for (let [key, subset] of S.entries()) {
            if (x % key === 0 && subset.size > maxSubset.size) {
                maxSubset = new Set(subset);
            }
        }
        maxSubset.add(x);
        S.set(x, maxSubset);
    });
    let largest = new Set();
    for (let subset of S.values()) {
        if (subset.size > largest.size) {
            largest = subset;
        }
    }

    return Array.from(largest);
};