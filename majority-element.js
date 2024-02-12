//question link - https://leetcode.com/problems/majority-element/description/
// difficulty - medium



/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
     let candidate = null;
    let count = 0;

    // Find potential majority element
    for (let num of nums) {
        if (count === 0) {
            candidate = num;
        }
        count += num === candidate ? 1 : -1;
    }
    count = 0;
    for (let num of nums) {
        if (num === candidate) {
            count++;
        }
    }
    if (count > nums.length / 2) {
        return candidate;
    } else {
        throw new Error("No majority element found.");
    }
};