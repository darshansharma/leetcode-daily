// questionLink:  https://leetcode.com/problems/missing-number
// difficulty  :  Easy


/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let sum = 0;
    let max = 0;
    let isZeroPresent = false;
    for(let i =0; i<nums.length; i++) {
        sum += nums[i];
        if(max < nums[i]) {
            max = nums[i];
        }
        if(nums[i] === 0) {
            isZeroPresent = true;
        }
    }
    let res = (max*(max+1)/2 - sum);
    if(res === 0){
        if(!isZeroPresent) return 0;
        return max+1;
    }
    return res;
};