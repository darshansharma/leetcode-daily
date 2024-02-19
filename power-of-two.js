// quest link: https://leetcode.com/problems/power-of-two/description
// difficulty: easy

/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    if(n <= 0) return false;
    return (n & (n - 1)) === 0;
};