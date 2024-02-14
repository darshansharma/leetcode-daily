//   Question:   https://leetcode.com/problems/rearrange-array-elements-by-sign/description
//   Difficulty: Medium


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var rearrangeArray = function(nums) {
    let pa = [];
    let na = [];
    let arr = [];
    pa = nums.filter((elem) => elem >= 0);
    na = nums.filter((elem) => elem < 0);
    let i=0,j=0;
    while(i<pa.length && j<na.length) {
        arr.push(pa[i]);
        i++;
        arr.push(na[j]);
        j++;
    }
    while(i<pa.length) {
        arr.push(pa[i]);
        i++;
    }
    while(j<pa.length) {
        arr.push(na[i]);
        j++;
    }
    return arr;
};