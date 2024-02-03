    // Question link - https://leetcode.com/problems/partition-array-for-maximum-sum
    // Difficulty - Medium
    // Date Attempted - 03 Feb 2024
    // Attempt Again (I picked up solution). Not mine. 

/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */

var DP;
var maxSumAfterPartitioning = function(arr, k) {
    let n = arr.length;

    let dp = Array(n+1).fill(0);

    for(let start = n-1; start>=0; start--) {
        let currMax = 0;
        let end = Math.min(n, start+k);

        for(let i=start; i<end; i++) {
            currMax = Math.max(currMax, arr[i]);
            dp[start] = Math.max(dp[start], dp[i+1] +currMax*(i-start+1))
        }
    }
    return dp[0];

};
