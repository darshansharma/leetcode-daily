    // Question link - https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/
    // Difficulty - Easy but I made it difficult for myself, otherwise on my first approach I was doing right thing by sorting
    // Date Attempted - 01 Feb 2024


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[][]}
 */
var divideArray = function(nums, k) {
    let arrayLength = nums.length;
    let res = [];
    nums.sort((a,b)=>a-b);
    for(let i=0; i<nums.length; i=i+3) {
        if((nums[i+2] - nums[i]) > k) return [];
        else {
            res.push([nums[i],nums[i+1],nums[i+2]]);
        }
    }
    if(res.length !== arrayLength/3) return [];
    return res;
      
};